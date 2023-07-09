#include<bits/stdc++.h>

using namespace std;

int n;
int answer=0;

typedef struct 
{
    int p;
    int in;
}balloon;


int pointCheck(balloon arr[],balloon path[])
{
    balloon dup[n];
    for(int i=0;i<n;i++)
        dup[i]=arr[i];
    int score=0;
    int l,r;
    
    for(int i=0;i<n;i++)
    {
        l=-1;
        r=-1;
        int index=path[i].in;
        int c=1;
        while(index-c>=0)
        {
            if(dup[index-c].p==-1 && index-c>=0)
            {
                c++;
                continue;
            }
            else if(index-c>=0 && dup[index-c].p!=-1)
            {
                l=dup[index-c].p;
                break;
            }
        }

        c=1;

        while(index+c<n)
        {
            if(dup[index+c].p==-1 && index+c<n)
            {
                c++;
                continue;
            }
            else if(index+c<n && dup[index+c].p!=-1)
            {
                r=dup[index+c].p;
                break;
            }
        }
       // cout<<"l: "<<l<<" r: "<<r<<endl;
        if(l==-1 && r==-1)
            score+=dup[index].p;
        if(l!=-1 && r!=-1)
            score+=l*r;
        if(l!=-1 && r==-1)
            score+=l;
        if(l==-1 && r!=-1)
            score+=r;
        dup[index].p=-1;
    }

    return score;
}

void solve(int nodes,balloon arr[], vector<bool> &visited,balloon path[])
{
    if(nodes == n)
    {
        int score;
        score=pointCheck(arr,path);
        if(score>answer)
        {
            answer=score;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            path[nodes]=arr[i];
            solve(nodes+1,arr, visited,path);
            visited[i]=false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        cin >> n;
        balloon arr[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i].p;
            arr[i].in=i;
        }

        vector<bool> visited(n,false);
        balloon path[n];
        solve(0,arr, visited, path);
        cout << "Answer: "<<answer<<endl;
    }
}

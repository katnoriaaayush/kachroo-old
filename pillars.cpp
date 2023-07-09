#include<bits/stdc++.h>

using namespace std;

int n,answer;


void solve(int p1, int p2, int arr[], bool visited[])
{
    if(p1==p2)
    {
        if(p1>answer)
            answer=p1;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            solve(p1+arr[i],p2,arr,visited);
            solve(p1,p2+arr[i],arr,visited);
            visited[i]=false;
        }
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    answer=0;
     cin >> n;
     int arr[n]={0};
     bool visited[n]={false};
     for(int i=0;i<n;i++)
     {
        cin >> arr[i];
     }
     solve(0,0,arr,visited);
     cout<<answer<<endl;
  }
}
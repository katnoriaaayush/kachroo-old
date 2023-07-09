#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x; int y; int index;
}Point;

int n;
Point loc[10];
int answer;

int distance(Point i, Point j)
{
    int ans=abs(i.x-j.x)+abs(i.y-j.y);
}

void minDistance(Point src, Point dest,int nodes, int value,bool visited[])
{
    //base case
    if(n==nodes)
    {
        cout<<endl;
       // cout<<src.x<< " "<<src.y<<" "<<dest.x<<" "<<dest.y<<endl;
        value+=distance(src,dest);
        if(value<answer)
            answer=value;
        return;
    }

    //recursive case
    
    for(int i=1;i<=n;i++)
    {
        
        if(!visited[i])
        {   
            visited[i]=true;
            nodes+=1;
            minDistance(loc[i],dest,nodes,value+distance(src,loc[i]),visited);
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
    cin >> n;
    cin >> loc[0].x >> loc[0].y >> loc[n+1].x >> loc[n+1].y;
    bool visited[10]={false};
    loc[0].index=0; loc[n+1].index=n+1; visited[0]=false; visited[n+1]=false;
    for(int i=1;i<=n;i++)
    {
        cin >> loc[i].x >> loc[i].y;
        visited[i]=false;
        loc[i].index=i;
    }
    answer=INT_MAX;
    minDistance(loc[0],loc[n+1],0,0,visited);
    cout<<answer<<endl;
  }
}
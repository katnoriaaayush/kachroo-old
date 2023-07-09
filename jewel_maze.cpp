#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x;
    int y;
}Point;

int N;
int maze[11][11];
bool visited[11][11];
int dist[11][11];
int path[11][11];
int answer;

int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};

bool isValid(Point i)
{
    if(i.x>=0 && i.x<N && i.y>=0 && i.y<N)
        return true;
    else
    return false;
}

void solve(Point src, Point dest, int count)
{
    if(src.x==dest.x && src.y==dest.y)
    {
        if(count > answer)
        {
            answer=count;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(visited[i][j])
                        path[i][j]=3;
                    else
                        path[i][j]=maze[i][j];
                }
            }
        }
            
    }

    for(int i=0;i<4;i++)
    {
        Point np;
        np.x=src.x+dirx[i];
        np.y=src.y+diry[i];

        if(!visited[np.x][np.y] && maze[np.x][np.y]!=1 && isValid(np))
        {
            visited[np.x][np.y]=true;
            if(maze[np.x][np.y]==0)
                solve(np,dest,count);
            else if(maze[np.x][np.y]==2)
                solve(np,dest,count+1);
            visited[np.x][np.y]=false;
        }
    }

}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> maze[i][j];
            visited[i][j]=false;
            dist[i][j]=0;
        }
    }
    Point src,dest;
    src.x=0;src.y=0;
    dest.x=N-1;dest.y=N-1;
    answer=0;
    visited[src.x][src.y]=true;
    solve(src,dest,0);
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<answer<<endl;
  }
}
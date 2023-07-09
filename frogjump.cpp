#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x;
    int y;
}Point;

Point src,dest;

int n;
int arr[100][100];
bool visited[100][100];
int dist[100][100];

int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};

bool isValid(Point p){
	return (p.x>=0 && p.x<n && p.y>=0 && p.y<n);
}


int bfs()
{
    if(src.x==dest.x && src.y==dest.y)
    {
        return dist[src.x][src.y];
    }

    if(arr[src.x][src.y]==0)
    {
        return -1;
    }

    queue<Point> q;
    q.push(src);
    visited[src.x][src.y]=true;

    while(!q.empty())
    {
        Point p;
        p=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            Point np;
            np.x=p.x+dirx[i];
            np.y=p.y+diry[i];

            if(isValid(np) && !visited[np.x][np.y] && arr[np.x][np.y]==1)
            {
                if(i==0 || i==2)
                {
                    dist[np.x][np.y]=dist[p.x][p.y];
                }
                else 
                {
                    dist[np.x][np.y]=dist[p.x][p.y]+1;
                }
                visited[np.x][np.y]=true;
                q.push(np);
            }
        }
    }    
    return dist[dest.x][dest.y];

}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
            visited[i][j]=false;
            dist[i][j]=0;
        }
    }
    cin >> src.x >> src.y >> dest.x >> dest.y;

    cout<<"Answer: "<<bfs()<<endl;
  }
}
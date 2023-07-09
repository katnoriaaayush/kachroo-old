#include<bits/stdc++.h>

using namespace std;

typedef struct
{
  int x;
  int y;
  int d;
}Point;

int n,m;
int matrix[100][100];
bool visited[100][100];
Point src;

int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
int ans;

bool isValid(Point i)
{
  if(i.x>=0 && i.x<n && i.y>=0 && i.y<n)
    return true;
    else
      return false;
}

void isContaminated()
{
  src.x+=-1;
  src.y+=-1;
  visited[src.x][src.y]=true;
  src.d=1;

  queue<Point> q;
  q.push(src);

  while(!q.empty())
  {
    Point p;
    p=q.front();
    q.pop();

    Point np;
    for(int i=0;i<4;i++)
    {
      np.x=p.x+dirx[i];
      np.y=p.y+diry[i];

      if(isValid(np) && !visited[np.x][np.y] && matrix[np.x][np.y]==1)
      {
        visited[np.x][np.y]=true;
        np.d=p.d+1;
        ans=np.d;
        q.push(np);
      }
    }
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        cin >> matrix[i][j];
        visited[i][j]=false;
      }
    }
    cin >> src.x >> src.y;
  
  isContaminated();
  cout<<ans<<endl;
  }
}
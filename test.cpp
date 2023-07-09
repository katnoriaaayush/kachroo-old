#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x,y;
    int level;
}Point;

int n,m;
int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};

void init(vector<vector<int>>& visited)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            visited[i][j]=0;
        }
    }
}

bool isValid(Point i)
{
    if(i.x>=0 && i.x<n && i.y>=0 &&i.y<n)
        return true;
    else
        return false;
}

void bfs(Point src, vector<vector<int>>& visited, vector<vector<int>> matrix)
{
    visited[src.x][src.y]=1;
    
    queue<Point> q;
    
    q.push(src);

    while (!q.empty())
    {
        Point p,np;
        p=q.front();
        q.pop();

       /* int count =0;
        for(int i=0; i<m;i++)
        {
            if(visited[gems[i].x][gems[i].y]>0)
            {
                count+=1;
            }
        }

        if(count==m)
            return;*/

        for(int j=0;j<4;j++)
        {
            np.x=p.x+dirx[j];
            np.y=p.y+diry[j];

            if(isValid(np) && visited[np.x][np.y]==0 && matrix[np.x][np.y]==1)
            {
                np.level=p.level+1;
                visited[np.x][np.y] = np.level;
                q.push(np);
            }
        }

    }
    
}


int main()
{
  Point p;
  p.x=0;
  p.y=0; p.level=0;
  cin >> n;
  vector<vector<int>> matrix(n,vector<int> (n,0));
  vector<vector<int>> visited(n,vector<int>(n,0));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
        cin>>matrix[i][j];
    }
  }
  bfs(p,visited,matrix);

  cout << endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
        cout<<visited[i][j]<< " ";
    }
    cout<<endl;
  }
}
#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x;int y;int d;
}Point;

int gnum;
int n;
int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};

bool isValid(Point i)
{
    if(i.x>=0 && i.x<n && i.y>=0 &&i.y<n)
        return true;
    else
        return false;
}

void calcDistance(Point gems[], vector<vector<bool>> visited,vector<vector<int>> matrix,vector<int> &maxdist)
{
    for(int i=0;i<gnum;i++)
    {
        visited[gems[i].x][gems[i].y]=true;

        queue<Point> q;
        q.push(gems[i]);
        int level=0;
        while(!q.empty())
        {
            Point p;
            p=q.front();
            q.pop();

            Point np;
            for(int j=0;j<4;j++)
            {
                np.x=p.x+dirx[j];
                np.y=p.y+diry[j];

                if(isValid(np) && !visited[np.x][np.y] && matrix[np.x][np.y]==1)
                {
                    visited[np.x][np.y]=true;
                    np.d=p.d+1;
                    level=np.d;
                    q.push(np);
                }
            }

        }
        maxdist[i]=level;
        cout<<level<<endl;
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {
                visited[k][l]=false;
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
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    
    cin >> gnum;
    Point gems[gnum];
    for(int i=0;i<gnum;i++)
    {
        cin>>gems[i].x>>gems[i].y;
        gems[i].d=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<bool>> visited(n,vector<bool> (n,false));
    vector<int> maxdist(gnum,0);
    calcDistance(gems,visited,matrix,maxdist);
  }
}
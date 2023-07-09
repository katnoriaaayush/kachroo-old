#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x;int y;int d;
}piece;

int N,M;
piece pos_a,pos_d;
int count;
int dirx[]={-2,-1,1,2,2,1,-1,-2};
int diry[]={1,2,2,1,-1,-2,-2,-1};

bool isValid(int i, int j)
{
    if(i>0 && i<=N && j>0 && j<=M)
        return true;
    else
        return false;
}

int solve(piece pos,int nodes,vector<vector<bool>> visited)
{
    queue <piece> q;
    q.push(pos);
    visited[pos.x][pos.y]=true;

    while(!q.empty())
    {
        piece p=q.front();
        q.pop();

        if(p.x==pos_d.x && p.y == pos_d.y)
        {
            return p.d;
        }

        for(int i=0;i<8;i++)
        {
            int nx=p.x+dirx[i];
            int ny=p.y+diry[i];
            if(isValid(nx,ny))
            {
                if(!visited[nx][ny])
                {
                    piece np;
                    np.x=nx; np.y=ny;np.d=p.d+1;
                    q.push(np);
                    visited[nx][ny]=true;
                }
            }
        }
    }
    return -1;
}


int main()
{
    int t;
    cin >> t;
    int count=1;
    while(t--)
    {
        cin>> N >> M;
        cin >> pos_a.x >> pos_a.y >> pos_d.x >> pos_d.y;
        vector<vector<bool>> visited(N+1,vector<bool> (M+1,false));
        piece start;
        start.x=pos_a.x;start.y=pos_a.y;start.d=0;
        int ans=solve(start, 0,visited);
        cout<<"Case #" <<count<<"\n"<<ans << endl;
        count++;
    }
}
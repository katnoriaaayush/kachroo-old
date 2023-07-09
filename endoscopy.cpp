#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x,y;
}Point;

typedef struct
{
bool left;   bool up;
bool right;  bool down;
}Node;

int N,M,sx,sy,len;
int result;
int arr[1005][1005];
bool visited[1005][1005];
int dis[1005][1005];

Node pipe[1005][1005];


bool isValid(int i, int j)
{
    if(i>=0 && i<N && j>=0&&j<M)
        return true;
    else   
        return false;
}

void bfs()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            visited[i][j]=false;
            dis[i][j]=0;
        }
    }   

    dis[sx][sy] = 1;
    visited[sx][sy]=true;

    if(arr[sx][sy]==0)
    {
        result=0;
        return;
    }
    Point pos;
    pos.x=sx; pos.y=sy;
    queue <Point> q;
    q.push(pos);

    while(!q.empty())
    {
        Point p;
        p=q.front();
        q.pop();

        if(1+ dis[p.x][p.y]<=len)
        {
            //Down
            if(isValid(p.x+1,p.y) && !visited[p.x+1][p.y] && pipe[p.x+1][p.y].up && pipe[p.x][p.y].down)
            {
                visited[p.x+1][p.y]=true;
                dis[p.x+1][p.y]=1+dis[p.x][p.y];
                result++;
                Point np;
                np.x=p.x+1;
                np.y=p.y;
                q.push(np);
            }

            //Up
            if(isValid(p.x-1,p.y) && !visited[p.x-1][p.y] && pipe[p.x-1][p.y].down && pipe[p.x][p.y].up)
            {
                visited[p.x-1][p.y]=true;
                dis[p.x-1][p.y]=1+dis[p.x][p.y];
                result++;
                Point np;
                np.x=p.x-1;
                np.y=p.y;
                q.push(np);
            }

            //Left
            if(isValid(p.x,p.y-1) && !visited[p.x][p.y-1] && pipe[p.x][p.y-1].right && pipe[p.x][p.y].left)
            {
                visited[p.x][p.y-1]=true;
                dis[p.x][p.y-1]=1+dis[p.x][p.y];
                result++;
                Point np;
                np.x=p.x;
                np.y=p.y-1;
                q.push(np);
            }

            //Right
            if(isValid(p.x,p.y+1) && !visited[p.x][p.y+1] && pipe[p.x][p.y+1].left && pipe[p.x][p.y].right)
            {
                visited[p.x][p.y+1]=true;
                dis[p.x][p.y+1]=1+dis[p.x][p.y];
                result++;
                Point np;
                np.x=p.x;
                np.y=p.y+1;
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
    result=1;
     cin >> N >> M >> sx >> sy >> len;
     for(int i=0;i<N;i++)
     {
        for(int j=0;j<M;j++)
        {
            cin >> arr[i][j];

            if(arr[i][j]==1)
            {
                pipe[i][j].left=true;
                pipe[i][j].right=true;
                pipe[i][j].up=true;
                pipe[i][j].down=true;
            }

            else if( arr[i][j] == 2 )
            {
                pipe[i][j].left = false;
                pipe[i][j].right = false;
                pipe[i][j].up = true;
                pipe[i][j].down = true;
	        }
	        else if( arr[i][j] == 3 ){
                pipe[i][j].left = true;
                pipe[i][j].right = true;
                pipe[i][j].up = false;
                pipe[i][j].down = false;	                
            }
	        else if( arr[i][j] == 4 ){
                pipe[i][j].left = false;
                pipe[i][j].right = true;
                pipe[i][j].up = true;
                pipe[i][j].down = false;
            }
	        else if( arr[i][j] == 5 ){
                pipe[i][j].left = false;
                pipe[i][j].right = true;
                pipe[i][j].up = false;
                pipe[i][j].down = true;
            }
	        else if( arr[i][j] == 6 ){
                pipe[i][j].left = true;
                pipe[i][j].right = false;
                pipe[i][j].up = false;
                pipe[i][j].down = true;
            }
	        else if( arr[i][j] == 7 ){
                pipe[i][j].left = true;
                pipe[i][j].right = false;
                pipe[i][j].up = true;
                pipe[i][j].down = false;	                
            }
	        else{
                pipe[i][j].left = false;
                pipe[i][j].right = false;
                pipe[i][j].up = false;
                pipe[i][j].down = false;	                
            }
        }
     }
     bfs();
     cout<<result<<endl;
}
}


/*

2 
5 6 2 1 3 
0 0 5 3 6 0 
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
5 6 2 2 6 
3 0 0 0 0 3 
2 0 0 0 0 6 
1 3 1 1 3 1 
2 0 2 0 0 2 
0 0 4 3 1 1

*/
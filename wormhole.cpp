#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    int x; int y;
}Point;

typedef struct
{
    Point from;
    Point to;
    int cost;
}wormhole;

int num;
int answer;

int calcDistance(Point from,Point to)
{
    int ans=abs(from.x-to.x)+abs(from.y-to.y);
    return ans;
}

void minDistance(Point src, Point dest,int value,wormhole hole[],vector<bool> &visited)
{
    int temp=value+calcDistance(src,dest);
    answer=min(temp,answer);

    for(int i=0;i<num;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            int val=calcDistance(src,hole[i].from);
            minDistance(hole[i].to,dest,value+val+hole[i].cost,hole,visited);
            val=calcDistance(src,hole[i].to);
            minDistance(hole[i].from,dest,value+val+hole[i].cost,hole,visited);
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
    
    cin >> num;

    Point src,dest;
    cin >> src.x >> src.y >> dest.x>>dest.y;

    wormhole hole[num];
    vector<bool> visited(num,false);

    for(int i=0;i<num; i++)
    {
        cin >> hole[i].from.x >> hole[i].from.y;
        cin>> hole[i].to.x >> hole[i].to.y >> hole[i].cost;
    }
    answer=calcDistance(src,dest);
    minDistance(src,dest,0,hole,visited);
   cout<<"Answer: "<<answer<<endl; 
  }
}
#include<iostream>
#include<vector>

using namespace std;

bool dfs(int node,int parent,int color, int visited[], vector<int> graph[])
{
    visited[node]=color;

    for(auto nbr:graph[node])
    {
        if(!visited[nbr])
        {
            bool subprob=dfs(nbr,node, 3-color,visited, graph);
            if(!subprob)
                return false;
        }
        else if(nbr!=parent && visited[nbr]==color)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N,M;
    cin >> N>>M;
    vector<int> graph[N];
    int visited[N];
    for(int i=0;i<N;i++)
    {
        visited[i]=0;
    }
    while(M--)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=0;i<N;i++)
    {
        if(visited[i]==0)
        {
            int color=1;
            bool ans=dfs(i,-1,color,visited,graph);
            if(ans==false)
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(visited[i]==1)
        {
            cout<< i<<" ";
        }
    }
    
}
#include<bits/stdc++.h>

using namespace std;

bool dfs_helper(vector<int>graph[], int node,int parent, int *visited,int color)
{
    visited[node]=color;

    for(auto nbr : graph[node])
    {
        if(!visited[nbr])
        {
            int subprob=dfs_helper(graph, nbr,node, visited,3-color);
            if(subprob==false)
                return false;   
        }
        else if(nbr!=parent &&  color==visited[nbr])
        {
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int N)
{
    int visited[N]={0};
    int color=1;
    int ans=dfs_helper(graph,0,-1,visited,color);
}

int main()
{
    int N,M;
    cin >> N>>M;

    vector<int> graph[N];

    while(M--)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    //coloring the nodes


    
}
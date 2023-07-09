#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int parent, vector<bool> &visited, vector<int> graph[])
{
    visited[node]=true;
    for(auto nbr : graph[node])
    {
        if(!visited[nbr])
        {
            bool subprob=dfs(nbr,node,visited,graph);
            if(subprob==true)
                return true;
        }
        else if(nbr!=parent)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> graph[N];
    while(M--)
    {
        int x;int y;
        cin >> x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<bool> visited(N,false);

    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            bool ans = dfs(i,-1,visited,graph);
            if(ans)
            {
                cout<<"Cycle Detected"<<endl;
                return 0;
            }
        }
    }
    cout<<"No Cycle Present"<<endl;
}
#include<iostream>
#include<vector>

using namespace std;

bool dfs(int node, vector<bool> &visited, vector<bool> &stack, vector<int> graph[])
{
    visited[node]=true;
    stack[node]=true;

    for(auto nbr: graph[node])
    {
        if(!visited[nbr])
        {
            bool subprob=dfs(nbr, visited, stack, graph);
            if(!subprob)
            {
                return false;
            }
        }
        else if(stack[nbr])
        {
            return false;
        }
    }
    stack[node]=false;
    return true;
}

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> graph[N];
    while (M--)
    {
        int x,y;
        cin >> x>> y;
        graph[x].push_back(y);
    }
    vector<bool> visited(N,false);
    vector<bool> stack(N,false);

    for(int i=0;i<N;i++)
    {
        bool ans = dfs(i,visited, stack, graph);
        if(!ans)
        {
            cout<<"Cycle Detected"<<endl;
            return 0;
        }
    }
    cout<<"Cycle not Detected"<<endl;
    
}
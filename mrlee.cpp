#include<bits/stdc++.h>

using namespace std;

int n;
int answer;


void minDistance(int src,int value,int nodes,vector<bool> &visited,vector<vector<int>> &matrix)
{
   if(nodes==n-1)
   {
        if(matrix[src][0]!=0)
        {
            value+=matrix[src][0];
            if(value<answer)
                answer=value;
        }
            
        return;
   }

   for(int i=0;i<n;i++)
   {
    if(!visited[i]&&matrix[src][i]!=0)
    {
        visited[i]=true;
        minDistance(i,value+matrix[src][i],nodes+1,visited,matrix);
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
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    vector<bool> visited(n,false);
    answer=INT_MAX;
    visited[0]=true;
    minDistance(0,0,0,visited,matrix);
    cout<< answer<<endl;
  }
}
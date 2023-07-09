#include<bits/stdc++.h>

using namespace std;

int n,m;
int num;

typedef struct
{
    int x; int y;
}Point;

void solve(vector<vector<int>> matrix)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            
        }
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin >> n>> m;
    vector<vector<int>> matrix(n, vector<int>(m,0));
    cin >> num;
    Point holes[num];
    for(int i=0;i<num;i++)
    {
        cin >> holes[i].x >> holes[i].y;
        matrix[holes[i].x][holes[i].y]=1;
    }

    solve(matrix);
  }
}
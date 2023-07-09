#include<bits/stdc++.h>

using namespace std;

void updateMatrix(int row, vector<vector<int>> &matrix)
{
    if(row<0)
    {
        return;
    }
    int upLimit=max(0,row-4);
    for(int i=row;i>=upLimit;i--)
    {
        for(int j=0;j<=4;j++)
        {
            if(matrix[i][j]==2)
                matrix[i][j]=0;
        }
    }
}

int findMaxPoints(int row, int column, int bombs, vector<vector<int>> &matrix)
{
    if(row<=0||column<0||column>=5)
        return 0;
    
    int answer=0;
    if(row>0 && matrix[row-1][column]!=2)
    {
        answer=max(answer,(matrix[row-1][column]==1?1:0)+findMaxPoints(row-1,column,bombs,matrix));
    }
    if(row>0 && column>0 && matrix[row-1][column-1]!=2)
    {
        answer=max(answer,(matrix[row-1][column-1]==1?1:0)+findMaxPoints(row-1,column-1,bombs,matrix));
    }
    if(row>0 && column<5 && matrix[row-1][column+1]!=2)
    {
        answer=max(answer,(matrix[row-1][column+1]==1?1:0)+findMaxPoints(row-1,column+1,bombs,matrix));
    }
    if(answer==0 && bombs>0)
    {
        updateMatrix(row-1,matrix);
        answer=findMaxPoints(row,column,bombs-1,matrix);
    }
    return answer;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int row;
    cin>>row;
    vector<vector<int>> matrix(row+2,vector<int>(5,0));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout<<findMaxPoints(row,2,1,matrix)<<endl;
  }
}
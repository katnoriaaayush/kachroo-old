
            cin >>matrix[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
                continue;
            Point p;
            p.x=i;
            p.y=j;
            bfs(p,matrix[i][j],matrix,visited);
            int temp=0;
            for(int k=0;k<m;k++)
            {
                if(visited[gems[k].x][gems[k].y]>temp)
                {
                    temp=visited[gems[k].x][gems[k].y];
                }
            }
            if(temp<answer)
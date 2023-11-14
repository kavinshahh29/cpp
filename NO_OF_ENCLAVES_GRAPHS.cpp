#include<bits/stdc++.h>
using namespace std;
int numberOfEnclaves(vector<vector<int>> &grid) {
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            if(visit[i][0]==false and grid[i][0]==1)
            {
                dfs(i,0,visit,grid);
            }
            if(visit[i][grid[0].size()-1]==false and grid[i][grid[0].size()-1]==1)
            {
                dfs(i,grid[0].size()-1,visit,grid);
            }
            
        }
        for(int i=0;i<grid[0].size();i++)
        {
            if(visit[0][i]==false and grid[0][i]==1)
            {
                dfs(0,i,visit,grid);
            }
            if(visit[grid.size()-1][i]==false and grid[grid.size()-1][i]==1)
            {
                dfs(grid.size()-1,i,visit,grid);
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visit[i][j]==false and grid[i][j]==1)
                {
                    count++;
                }
                
            }
        }
        return count;
    }
    void dfs(int row,int col,vector<vector<bool>>&visit,vector<vector<int>>&grid)
    {
        visit[row][col]=true;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int rowindex=row+rowmatrix[i];
            int colindex=col+colmatrix[i];
            if(rowindex>=0 and rowindex<grid.size() and colindex>=0 and colindex<grid[0].size() and visit[rowindex][colindex]==false and grid[rowindex][colindex]==1)
            {
                dfs(rowindex,colindex,visit,grid);
            }
        }
    }
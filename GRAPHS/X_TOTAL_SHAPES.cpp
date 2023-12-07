#include<bits/stdc++.h>
using namespace std;




int xShape(vector<vector<char>>& grid) 
    {
        int count=0;
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visit[i][j]==false and grid[i][j]=='X')
                {
                    dfs(i,j,grid,visit);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<bool>>&visit)
    {
        visit[row][col]=true;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int rowin=row+rowmatrix[i];
            int colin=col+colmatrix[i];
            if(rowin>=0 and rowin<grid.size() and colin>=0 and colin<grid[0].size() and visit[rowin][colin]==false and grid[rowin][colin]=='X')
            {
                dfs(rowin,colin,grid,visit);
            }
            
        }
    }
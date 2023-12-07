#include<bits/stdc++.h>
using namespace std;


bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
        
        int rowin=0,colin=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visit[i][j]==false and grid[i][j]==1)
                {
                    dfs(i,j,visit,grid,rowin,colin);
                }
            }
        }
        if(visit[rowin][colin]==true)
        return true;
        return false;
    }
    bool dfs(int row,int col,vector<vector<bool>>&visit,vector<vector<int>>&grid,int &rowin,int &colin)
    {
        visit[row][col]=true;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int r=rowmatrix[i]+row;
            int c=colmatrix[i]+col;
            if(r>=0 and r<grid.size() and c>=0 and c<grid[0].size() and  grid[r][c]==3 and visit[r][c]==false)
            {
                if(dfs(r,c,visit,grid,rowin,colin)==true)
                return true;
            }
            else if(r>=0 and r<grid.size() and c>=0 and c<grid[0].size() and  grid[r][c]==2)
            {
                visit[r][c]=true;
                rowin=r;
                colin=c;
                return true;
            }
            else
            continue;
            
        }
        return false;
    }

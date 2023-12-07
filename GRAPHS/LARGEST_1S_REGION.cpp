#include<bits/stdc++.h>
using namespace std;





 int findMaxArea(vector<vector<int>>& grid) {
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
        int maxi=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int ans=0;
                if(grid[i][j]==1 and visit[i][j]==false)
                {
                    dfs(i,j,grid,visit,ans);
                    
                    
                }
                if(ans>maxi)
                {
                    maxi=ans;
                }
            }
        }
        return maxi;
    }
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<bool>>&visit,int &ans)
    {
        visit[row][col]=true;
        ans++;
        int rowmatrix[]={0,-1,-1,-1,0,1,1,1};
        int colmatrix[]={-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<8;i++)
        {
            int rowin=row+rowmatrix[i];
            int colin=col+colmatrix[i];
            if(rowin>=0 and rowin<grid.size() and colin>=0 and colin<grid[0].size() and visit[rowin][colin]==false and grid[rowin][colin]==1)
            {
                dfs(rowin,colin,grid,visit,ans);
                
            }
        }
        
        
        
    }
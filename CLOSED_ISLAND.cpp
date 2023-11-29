#include<bits/stdc++.h>
using namespace std;


    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        vector<vector<int>>visit(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            if((matrix[i][0]==1 and visit[i][0]==0))
            {
                dfs(i,0,matrix,visit);
            }
            if(matrix[i][m-1]==1 and visit[i][m-1]==0)
            {
                dfs(i,m-1,matrix,visit);
            }
            
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]==1 and visit[0][i]==0)
            {
                dfs(0,i,matrix,visit);
            }
            if(matrix[n-1][i]==1 and visit[n-1][i]==0)
            {
                dfs(n-1,i,matrix,visit);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1 and visit[i][j]==0)
                {
                    ans++;
                    dfs(i,j,matrix,visit);
                }
            }
        }
        return ans;
        
    }
    void dfs(int row,int col,vector<vector<int>>&matrix,vector<vector<int>>&visit)
    {
        visit[row][col]=1;
        
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int rowin=rowmatrix[i]+row;
            int colin=colmatrix[i]+col;
            if(rowin>=0 and rowin<matrix.size() and colin>=0 and colin<matrix[0].size() and visit[rowin][colin]==0 and matrix[rowin][colin]==1)
            {
                dfs(rowin,colin,matrix,visit);
            }
            
            
        }
    }
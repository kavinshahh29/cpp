#include<bits/stdc++.h>
using namespace std;
   vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
         vector<vector<bool>>visit(mat.size(),vector<bool>(mat[0].size(),false));
         for(int i=0;i<n;i++)
         {
            if((visit[i][0]==false and mat[i][0]=='O'))
            {
                dfs(i,0,visit,mat);
            }
             if(visit[i][m-1]==false and mat[i][m-1]=='O')
            {
                dfs(i,m-1,visit,mat);
            }
            
         }
         for(int i=0;i<m;i++)
         {
             if((visit[0][i]==false and mat[0][i]=='O'))
             dfs(0,i,visit,mat);
             if((visit[n-1][i]==false and mat[n-1][i]=='O'))
             dfs(n-1,i,visit,mat);
         }
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(visit[i][j]==false and mat[i][j]=='O')
                 {
                     mat[i][j]='X';
                 }
             }
         }
         return mat;
    }
    void dfs(int row,int col,vector<vector<bool>>&visit,vector<vector<char>>&mat)
    {
        visit[row][col]=true;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int rowindex=row+rowmatrix[i];
            int colindex=col+colmatrix[i];
            if(rowindex>=0 and rowindex<mat.size() and colindex>=0 and colindex<mat[0].size()  and  mat[rowindex][colindex]=='O' and visit[rowindex][colindex]==false)
            {
                dfs(rowindex,colindex,visit,mat);
            }
        }
        
        
    }
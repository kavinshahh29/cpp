#include<bits/stdc++.h>
using namespace std;

// USING DFS APPROACH 
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
         
         vector<int>ans(operators.size(),-1);
         vector<vector<int>>grid(n,vector<int>(m,0));
         for(int i=0;i<operators.size();i++)
         {
             int count=0;
            
             
             int row=operators[i][0];
             int col=operators[i][1];
             grid[row][col]=1;
             vector<vector<bool>>visit(n,vector<bool>(m,false));
             for(int j=0;j<n;j++)
             {
                
                 for(int k=0;k<m;k++)
                 {
                     if(visit[j][k]==false and grid[j][k]==1)
                     {
                         count++;
                         dfs(j,k,visit,grid);
                         
                     }
                 }
             }
             ans[i]=count;
             
         }
         return ans;
         
    }
    void dfs(int row,int col,vector<vector<bool>>&visit,vector<vector<int>>&grid)
    {
        
        visit[row][col]=true;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        for(int l=0;l<4;l++)
        {
            int rowin=rowmatrix[l]+row;
            int colin=colmatrix[l]+col;
            if(rowin>=0 and rowin<grid.size() and colin>=0 and colin<grid[0].size() and visit[rowin][colin]==false and grid[rowin][colin]==1)
            {
                dfs(rowin,colin,visit,grid);
            }
        }
    }



// USING DSU APPROACH 



 vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        vector<int>ans;
         vector<int>parent(n*m);
         vector<int>rank(n*m,0);
         for(int i=0;i<n*m;i++)
         parent[i]=i;
         
         int rowmatrix[]={0,-1,0,1};
         int colmatrix[]={-1,0,1,0};
        int count=0;
        for(int i=0;i<operators.size();i++)
        {
            int row=operators[i][0];
            int col=operators[i][1];
            if(visit[row][col]==false)
            {
                visit[row][col]=true;
                count++;
                
                for(int j=0;j<4;j++)
                {
                    int rowin=row+rowmatrix[j];
                    int colin=col+colmatrix[j];
                    if(rowin>=0 and rowin<n and colin>=0 and colin<m and visit[rowin][colin]==true)
                    {
                        int ulp_adj=find(rowin*m+colin,parent);
                        int ulp_parent=find(row*m+col,parent);
                        if(ulp_adj!=ulp_parent)
                        {
                            if(rank[ulp_adj]>rank[ulp_parent])
                            {
                                parent[ulp_parent]=ulp_adj;
                            }
                            else if(rank[ulp_parent]>rank[ulp_adj])
                            {
                                parent[ulp_adj]=ulp_parent;
                            }
                            else
                            {
                                parent[ulp_adj]=ulp_parent;
                                rank[ulp_parent]++;
                            }
                            count--;
                        }
                    }
                }
                
                
            }
            ans.push_back(count);
            
        
        }
        return ans;
        
    }
    int find(int node,vector<int>&parent)
    {
        if(parent[node]==node)
        return node;
        
        return parent[node]=find(parent[node],parent);
    }






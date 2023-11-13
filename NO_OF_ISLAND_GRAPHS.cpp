#include<bits/stdc++.h>
using namespace std;


// APPROACH -1 USING DFS 

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
        
        int count=0;
        vector<vector<char>>adj=grid;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' and visit[i][j]==false)
                {
                    dfs(i,j,visit,adj,grid.size(),grid[0].size());
                    count++;
                    
                }
                
                
            }
        }
        return count;
        
        
        
    }
    void dfs(int rowindex,int colindex,vector<vector<bool>>&visit,vector<vector<char>>adj,int row,int col)
    {
        visit[rowindex][colindex]=true;
        int rowmatrix[8]={0,-1,-1,-1,0,1,1,1};
        int colmatrix[8]={-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<8;i++)
        {
            int rowi=rowmatrix[i]+rowindex;
            int coli=colmatrix[i]+colindex;
            if(rowi>=0 and rowi<row and coli>=0 and coli<col and visit[rowi][coli]==false and adj[rowi][coli]=='1')
            {
                dfs(rowi,coli,visit,adj,row,col);
            }
        }
        
        
    }
};






// APPROACH - 2 BFS APPROACH USING QUEUE OF PAIR 




class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<char>>adj=grid;
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visit[i][j]==false and adj[i][j]=='1')
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visit[i][j]=true;
                    count++;
                    while(!q.empty())
                    {
                        int rowi=q.front().first;
                        int coli=q.front().second;
                        q.pop();
                        int rowmatrix[8]={0,-1,-1,-1,0,1,1,1};
                        int colmatrix[8]={-1,-1,0,1,1,1,0,-1};
                        for(int k=0;k<8;k++)
                        {
                            int rowindex=rowi+rowmatrix[k];
                            int colindex=coli+colmatrix[k];
                            if(rowindex>=0 and rowindex<grid.size() and colindex>=0 and colindex<grid[0].size() and adj[rowindex][colindex]=='1' and visit[rowindex][colindex]==false)
                            {
                                visit[rowindex][colindex]=true;
                                q.push({rowindex,colindex});
                            }
                            
                            
                        }
                    }
                }
            }
            
        }
        return count;
    }
};
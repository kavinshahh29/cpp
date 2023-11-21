#include<bits/stdc++.h>

using namespace std;



 int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
          
          
          vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),1e8));
          
          queue<pair<int,pair<int,int>>>q;
          q.push({0,{source.first,source.second}});
          dist[source.first][source.second]=0;
          
          int rowmatrix[]={0,-1,0,1};
          int colmatrix[]={-1,0,1,0};
          while(!q.empty())
          {
              int rowin=q.front().second.first;
              int colin=q.front().second.second;
              int d=q.front().first;
              for(int i=0;i<4;i++)
              {
                  int row=rowin+rowmatrix[i];
                  int col=colin+colmatrix[i];
                  if(row>=0 and row<grid.size() and col>=0 and col<grid[0].size() and grid[row][col]==1 and dist[row][col]>d+1)
                  {
                      dist[row][col]=d+1;
                      q.push({dist[row][col],{row,col}});
                      
                  }
                  
              }
              q.pop();
              
          }
          if(dist[destination.first][destination.second]==1e8)
          return -1;
          
          return dist[destination.first][destination.second];
    }

    
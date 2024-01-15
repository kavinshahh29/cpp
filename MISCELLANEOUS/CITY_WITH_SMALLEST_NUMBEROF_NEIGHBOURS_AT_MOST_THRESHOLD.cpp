#include<bits/stdc++.h>

using namespace std;


int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                vector<vector<int>>grid(n,vector<int>(n,1e8));
                for(int i=0;i<edges.size();i++)
                {
                    grid[edges[i][0]][edges[i][1]]=edges[i][2];
                    grid[edges[i][1]][edges[i][0]]=edges[i][2];
                    
                }
                for(int i=0;i<n;i++)
                grid[i][i]=0;
                
                for(int k=0;k<n;k++)
                {
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(grid[i][k]!=1e8 and grid[k][j]!=1e8)
                            {
                                grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                            }
                        }
                    }
                }
                int maxi=n;
                int ans=-1;
                for(int i=0;i<n;i++)
                {
                    int count=0;
                    for(int j=0;j<n;j++)
                    {
                        if(grid[i][j]<=distanceThreshold)
                        {
                            count++;
                        }
                        
                    }
                    if(count<=maxi)
                    {
                        maxi=count;
                        
                        ans=i;
                    }
                }
                return ans;
                     
                     
                     
                     
                     
                     
                     
                     
                     
                 }
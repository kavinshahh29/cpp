#include<bits/stdc++.h>
using namespace std;

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int,int>>q;
	    vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),0));
	    vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                visit[i][j]=true;
	               
	            }
	        }
	    }
	    q.push({-2,-2});
	    int c=1;
	    int rowmatrix[]={0,-1,0,1};
	    int colmatrix[]={-1,0,1,0};
	     while(!q.empty())
	    {
	        int row=q.front().first;
	        int col=q.front().second;
            q.pop();
            if(row==-2 and col==-2)
            {
                c++;
                if(!q.empty())
                q.push({-2,-2});
                else
                return dist;
            }
            else{
            for(int k=0;k<4;k++)
	        {
	           int rowin=row+rowmatrix[k];
	           int colin=col+colmatrix[k];
	           if(rowin>=0 and rowin<grid.size() and colin>=0 and colin<grid[0].size() and visit[rowin][colin]==false)
	           {
	                    q.push({rowin,colin});
	                    visit[rowin][colin]=true;
	                    dist[rowin][colin]=c;
	           }
	                        
           }
        }
           
	                   
	  }
	  return dist;
	    
	    
	    
	}
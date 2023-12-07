#include<bits/stdc++.h>
using namespace std;




// using bfs approach 
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>visit(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    visit[i][j]=true;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                count++;
            }
        }
        if(count==0)
        return 0;
        int c=0;
        int tm=0;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            
            tm=max(t,tm);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int rowin=row+rowmatrix[i];
                int colin=col+colmatrix[i];
                if(rowin>=0 and rowin<grid.size() and colin>=0 and colin<grid[0].size() and visit[rowin][colin]==false and grid[rowin][colin]==1)
                {
                    visit[rowin][colin]=true;
                    q.push({{rowin,colin},t+1});
                    c++;
                }
            }
        }
        if(c==count)
        return tm;
        return -1;
    }


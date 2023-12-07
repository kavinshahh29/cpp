#include<bits/stdc++.h>
using namespace std;


 int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        typedef pair<int,pair<int,int>>p;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({grid[n-1][n-1],{n-1,n-1}});
        dist[n-1][n-1]=grid[n-1][n-1];
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        while(!pq.empty())
        {
            int cp=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
          //  cout<<row<<col<<endl;
            for(int i=0;i<4;i++)
            {
                int rowin=row+rowmatrix[i];
                int colin=col+colmatrix[i];
             //   cout<<"row: "<<rowin<<" col: "<<colin<<endl;
                if(rowin>=0 and rowin<n and colin>=0 and colin<n and dist[rowin][colin]>grid[rowin][colin]+cp)
                {
                    dist[rowin][colin]=grid[rowin][colin]+cp;
                  //  cout<<endl<<rowin<<" "<<colin<<" "<<endl;
                    pq.push({dist[rowin][colin],{rowin,colin}});
                    
                }
                
                
            }
        }

        return dist[0][0];
    }
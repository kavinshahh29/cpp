#include<bits/stdc++.h>


using namespace std;



    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++)
        {
            parent[i]=i;
            
        }
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        
        
        vector<int>dist(n+1,INT_MAX);
        dist[1]=0;
        typedef pair<int,int>p;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,1});
        while(!pq.empty())
        {
            int start=pq.top().second;
            int d=pq.top().first;
            for(auto it:adj[start])
            {
                int edg=it.first;
                int wt=it.second;
                if(dist[edg]>wt+d)
                {
                    dist[edg]=wt+d;
                    parent[edg]=start;
                    pq.push({dist[edg],edg});
                }
               
            }
             pq.pop();
        }
        
        if(parent[n]==n)
        return {-1};
        vector<int>ans;
        int node=n;
         while(node!=parent[node])
         {
             ans.push_back(node);
             node=parent[node];
             
         }
         ans.push_back(node);
         reverse(ans.begin(),ans.end());
         return ans;
         
        
        
    
        
    }
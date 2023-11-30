#include<bits/stdc++.h>
using namespace std;


int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        int parent[V];
        int rank[V]={0};
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        vector<pair<int,pair<int,int>>>pq;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                pq.push_back({it[1],{i,it[0]}});
                
            }
        }
        int ans=0;
        sort(pq.begin(),pq.end());
        for(int i=0;i<pq.size();i++)
        {
            int wt=pq[i].first;
            int u=pq[i].second.first;
            int v=pq[i].second.second;
            if(find(u,parent)==find(v,parent))
            continue;
            else
            {
                int ulp_u=find(u,parent);
                int ulp_v=find(v,parent);
                if(rank[ulp_u]>rank[ulp_v])
                {
                    parent[ulp_v]=ulp_u;
                }
                else if(rank[ulp_u]<rank[ulp_v])
                {
                    parent[ulp_u]=ulp_v;
                }
                else
                {
                    parent[ulp_u]=ulp_v;
                    rank[ulp_v]++;
                  
                    
                }
                ans+=wt;
                
            }
        }
        return ans;
    }
    int find(int x,int parent[])
    {
        if(parent[x]==x)
        return x;
        
        return parent[x]=find(parent[x],parent);
    }
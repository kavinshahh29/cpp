#include<bits/stdc++.h>
using namespace std;

	int counter=1;
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<vector<int>>ans;
        int low[V];
        int tim[V];
        vector<bool>visit(V,false);
        for(int i=0;i<V;i++)
        {
            if(visit[i]==false)
            dfs(i,-1,adj,ans,low,tim,visit);
            
        }
        
        for(int i=0;i<ans.size();i++)
        {
            int node1=ans[i][0];
            int node2=ans[i][1];
            if((node1==c and node2==d )or (node1==d and node2==c))
            {
                return 1;
                
            }
        }
        return 0;
        
    }
    void dfs(int src,int parent,vector<int>adj[],vector<vector<int>>&ans,int low[],int tim[],vector<bool>&visit)
    {
        visit[src]=true;
        low[src]=tim[src]=counter;
        counter++;
        for(auto it:adj[src])
        {
            if(it==parent)
            continue;
            if(visit[it]==false)
            {
                dfs(it,src,adj,ans,low,tim,visit);
                low[src]=min(low[src],low[it]);
                if(low[it]>tim[src])
                {
                    ans.push_back({src,it});
                }
            }
            else
            {
                low[src]=min(low[src],low[it]);
            }
        }
    }
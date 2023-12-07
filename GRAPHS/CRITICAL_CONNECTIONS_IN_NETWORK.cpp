#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
int counter=1;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       int low[n];
       int tim[n];
       vector<bool>visit(n,false);
       vector<int>adj[n];
       vector<vector<int>>ans;
       for(int i=0;i<connections.size();i++)
       {
           int node1=connections[i][0];
           int node2=connections[i][1];
           adj[node1].push_back(node2);
           adj[node2].push_back(node1);
       }
       dfs(0,-1,low,tim,visit,adj,ans);
return ans;
       


    }

    void dfs(int src,int parent,int low[],int tim[],vector<bool>&visit,vector<int>adj[],vector<vector<int>>&ans)
    {
        visit[src]=true;
        low[src]=tim[src]=counter;
        counter++;
        for(auto it:adj[src])
        {
            if(it==parent)continue;
            if(visit[it]==false)
            {
                dfs(it,src,low,tim,visit,adj,ans);
                low[src]=min(low[src],low[it]);
                if(low[it]>tim[src])
                {
                    ans.push_back({it,src});
                }

            }
            else
            {
                low[src]=min(low[src],low[it]);
            }
        }
    }
};
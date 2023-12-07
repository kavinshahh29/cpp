#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  int counter=1;
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>ans;
        int low[V];
        int tim[V];
        vector<bool>visit(V,false);
        vector<bool>mark(V,false);
        for(int i=0;i<V;i++)
        {
            if(visit[i]==false)
            {
                dfs(i,-1,visit,adj,low,tim,mark);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(mark[i]==true)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        return {-1};
        return ans;
    }
    void dfs(int src,int parent,vector<bool>&visit,vector<int>adj[],int low[],int tim[],vector<bool>&mark)
    {
        visit[src]=true;
        low[src]=tim[src]=counter;
        counter++;
        int child=0;
        for(auto it:adj[src])
        {
            if(it==parent)
            continue;
            
            if(visit[it]==false){
                dfs(it,src,visit,adj,low,tim,mark);
                low[src]=min(low[src],low[it]);
                if(low[it]>=tim[src] and parent!=-1)
                {
                    mark[src]=true;
                
               
                }
                    child++;
            
            }
            else
            {
                low[src]=min(low[src],tim[it]);
            }
        }
        if(child>1 and parent==-1)
        {
            mark[src]=true;
        }
        
    }
    
};
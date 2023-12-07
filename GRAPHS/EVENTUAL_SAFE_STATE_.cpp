#include<bits/stdc++.h>
using namespace std;




vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
         
         vector<int>ans;
         vector<bool>visit(V,false);
         vector<bool>pathvisit(V,false);
         for(int i=0;i<V;i++)
         {
             if(visit[i]!=true)
             {
                dfs(i,visit,adj,ans,pathvisit);
                 
             }
         }
         
         sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
    bool dfs(int start,vector<bool>&visit,vector<int>adj[],vector<int>&ans,vector<bool>&pathvisit)
    {
        visit[start]=true;
        pathvisit[start]=true;
        
        for(auto it:adj[start])
        {
            if(visit[it]==false)
            {
                if(dfs(it,visit,adj,ans,pathvisit)==true)
                return true;
            }
            else if(pathvisit[it]==true)
            {
                return true;
                
            }
            
            
        }
        
        pathvisit[start]=false;
        ans.push_back(start);
        return false;
        
        
    }




    
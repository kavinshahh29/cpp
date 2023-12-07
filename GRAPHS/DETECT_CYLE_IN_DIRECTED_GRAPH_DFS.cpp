#include<bits/stdc++.h>
using namespace std;

 bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool>visit(V+1,false);
        vector<bool>pathvisit(V+1,false);
        for(int i=0;i<V;i++)
        {
            if(visit[i]==false)
            {
                if(dfs(i,visit,pathvisit,adj,V)==true)
                return true;
            }
        }
        return false;
    }
    bool dfs(int start,vector<bool>&visit,vector<bool>&pathvisit,vector<int>adj[],int V)
    {
        visit[start]=true;
        pathvisit[start]=true;
        for(auto it:adj[start])
        {
            if(visit[it]==false)
            {
                if(dfs(it,visit,pathvisit,adj,V)==true)
                return true;
            }
            else if(pathvisit[it]==true)
            return true;
        }
        pathvisit[start]=false;
        return false;
    }
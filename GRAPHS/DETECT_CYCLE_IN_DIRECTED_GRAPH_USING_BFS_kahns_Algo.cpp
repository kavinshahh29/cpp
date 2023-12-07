#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int V, vector<int> adj[]) {
        
        int indegree[V+1]={0};
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                
            }
        }
        
        
        while(!q.empty())
        {
            
            int start=q.front();
            q.pop();
            
            for(auto it:adj[start])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    
                    q.push(it);
                }
            }
            
            
            
            
        }
        for(int i=0;i<V;i++)
        {
            if(indegree[i]!=0)
            return true;
            
        }
        return false;
        
    }
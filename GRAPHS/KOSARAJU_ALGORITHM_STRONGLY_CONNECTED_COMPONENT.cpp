#include<bits/stdc++.h>
using namespace std; 
 
 int kosaraju(int V, vector<vector<int>>& adj)
    {
       
        vector<bool>visit(V,false);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(visit[i]==false)
            {
                dfs(i,visit,adj,st);
            }
            
        }
        vector<vector<int>>newv(V);
        for(int i=0;i<V;i++)
        {
            visit[i]=false;
            int from=i;
            for(int j=0;j<adj[i].size();j++)
            {
                int to=adj[i][j];
                newv[to].push_back(from);
                
            }
        }
        int count=0;
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            if(visit[x]==false)
            {
                dfs(x,visit,newv);
                count++;
            }
            // cout<<x<<endl;
        }
       
       
        return count;
        
        
        
    }
    void dfs(int src,vector<bool>&visit,vector<vector<int>>&adj,stack<int>&st)
    {
        visit[src]=true;
       for(auto it:adj[src])
       {
           if(visit[it]==false)
           {
               dfs(it,visit,adj,st);
           }
       }
        st.push(src);
    }
    void dfs(int src,vector<bool>&visit,vector<vector<int>>&adj)
    {
        visit[src]=true;
        for(auto it:adj[src])
        {
            if(visit[it]==false)
            {
                dfs(it,visit,adj);
            }
        }
    }
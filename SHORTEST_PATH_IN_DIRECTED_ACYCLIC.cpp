#include<bits/stdc++.h>

using namespace std;


// USING SIMPLE APPROACH OPTIMAL
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            
        }
       vector<int>dist(N,INT_MAX);
       dist[0]=0;    
     
           
           
               dfs(0,0,adj,dist);
                  
           
           
       
       for(int i=0;i<N;i++)
       {
           if(dist[i]==INT_MAX)
           {
               dist[i]=-1;
           }
       }
       
     return dist;   
       
     }
     
     
     void dfs(int start,int d,vector<pair<int,int>>adj[],vector<int>&dist)
     {
         for(auto it:adj[start])
         {
             
             if(dist[it.first]>d+it.second)
             {
                 dist[it.first]=d+it.second;
                 dfs(it.first,dist[it.first],adj,dist);
             }
         }
         
         
         
     }



// USING DJIKSTRAS 


vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            
        }
        
        vector<int>dist(N,INT_MAX);
        set<pair<int,int>>st;
        st.insert({0,0});
        dist[0]=0;
        while(!st.empty())
        {
            auto s=*(st.begin());
            int start=s.second;
            int d=s.first;
            st.erase(s);
            for(auto it:adj[start])
            {
                int edg=it.first;
                int wt=it.second;
                if(dist[it.first]>it.second+d)
                {
                    if(dist[it.first]!=INT_MAX)
                    {
                        st.erase({dist[it.first],it.first});
                    }
                    dist[it.first]=it.second+d;
                    st.insert({dist[it.first],it.first});
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        return dist;
        
        
       
     }
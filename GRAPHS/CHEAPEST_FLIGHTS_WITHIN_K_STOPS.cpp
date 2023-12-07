#include<bits/stdc++.h>
using namespace std;


int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<vector<int>>adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            
        }
        typedef pair<int,pair<int,int>>p;
           priority_queue<p,vector<p>,greater<p>>pq;
           pq.push({0,{0,src}});
           vector<int>dist(n,INT_MAX);
           dist[src]=0;
           
           while(!pq.empty())
           {
               int stop=pq.top().first;
               int distance=pq.top().second.first;
               int start=pq.top().second.second;
               pq.pop();
               for(auto it:adj[start])
               {
                   if(stop<=k and distance!=INT_MAX and dist[it[0]]>it[1]+distance)
                   {
                    
                       dist[it[0]]=it[1]+distance;
                       pq.push({stop+1,{dist[it[0]],it[0]}});
                   }
               }
           }
           if(dist[dst]==INT_MAX)
           return -1;
           
           return dist[dst];
           
    }
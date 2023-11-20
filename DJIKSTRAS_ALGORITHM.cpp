#include<bits/stdc++.h>
using namespace std;

// USING PRIORITY QUEUE


    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         typedef pair<int,int>p;
          priority_queue<p,vector<p>,greater<p>>pq;
          
           pq.push({0,S});
           vector<int>dist(V,INT_MAX);
           dist[S]=0;
           while(!pq.empty())
           {
               int start=pq.top().second;
               int d=pq.top().first;
               pq.pop();
               for(auto it:adj[start])
               {
                   int ed=it[0];
                   int wt=it[1];
                   
                   if(dist[ed]>d+wt)
                   {
                       dist[ed]=d+wt;
                       pq.push({dist[ed],ed});
                   }
               }
           }
           
           
           
           return dist;
    }






// USING SET


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         set<pair<int,int>>st;
         st.insert({0,S});
         vector<int>dist(V,INT_MAX);
         dist[S]=0;
         
         while(!st.empty())
         {
             auto s=*(st.begin());
             int start=s.second;
             int d=s.first;
             for(auto it:adj[start])
             {
                 int ed=it[0];
                 int wt=it[1];
                 if(dist[ed]>wt+d)
                 {
                     if(dist[ed]!=INT_MAX)
                     {
                         st.erase({dist[ed],ed});
                     }
                     dist[ed]=wt+d;
                     st.insert({dist[ed],ed});
                 }
                 
             }
             st.erase(s);
         }
         return dist;
           
           
           
           
    }


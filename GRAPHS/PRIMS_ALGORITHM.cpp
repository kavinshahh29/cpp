
#include<bits/stdc++.h>
using namespace std;


int spanningTree(int V, vector<vector<int>> adj[])
    {
       
          typedef pair<int,int>q;
          priority_queue<q,vector<q>,greater<q>>pq;
          vector<int>dist(V,1e8);
          dist[0]=0;
          int sum=0;
          vector<bool>visit(V,false);
          pq.push({0,0});
          while(!pq.empty())
          {
              int start=pq.top().second;
              int d=pq.top().first;
              pq.pop();
              if(visit[start]==false)
              {
                  visit[start]=true;
                  sum+=d;
                  for(auto it:adj[start])
                  {
                      if(visit[it[0]]==false)
                      {
                          pq.push({it[1],it[0]});
                      }
                  }
              }
              
          }
          return sum;
    }
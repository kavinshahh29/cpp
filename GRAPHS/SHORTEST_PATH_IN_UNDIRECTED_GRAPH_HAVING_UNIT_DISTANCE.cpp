#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
           vector<int>adj[N];
           for(int i=0;i<edges.size();i++)
           {
               adj[edges[i][0]].push_back(edges[i][1]);
               adj[edges[i][1]].push_back(edges[i][0]);
           }
           vector<int>dist(N,INT_MAX);
           dist[src]=0;
           queue<pair<int,int>>q;
           q.push({src,0});
           while(!q.empty())
           {
               int start=q.front().first;
               int d=q.front().second;
               q.pop();
               for(auto it:adj[start])
               {
                   if(dist[it]>1+d)
                   {
                       dist[it]=1+d;
                       q.push({it,dist[it]});
                   }
               }
           }
           for(int i=0;i<N;i++)
           {
               if(dist[i]==INT_MAX)
               {
                   dist[i]=-1;
               }
           }
           return dist;
           
    }

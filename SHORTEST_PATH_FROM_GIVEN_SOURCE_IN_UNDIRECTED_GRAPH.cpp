#include<bits/stdc++.h>
using namespace std;




vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>distance(N,100000);
        distance[src]=0;
        queue<int>q;
        q.push(src);
        vector<bool>visit(N,false);
        visit[src]=true;
        vector<int>bfs;
        while(!q.empty())
        {
            int start=q.front();
            q.pop();
            bfs.push_back(start);
            for(auto it:adj[start])
            {
                if(visit[it]==false)
                {
                    q.push(it);
                    visit[it]=true;
                }
            }
        }
        
        for(int i=0;i<bfs.size();i++)
        {
            int start=bfs[i];
            
            for(auto it:adj[start])
            {
                
                if(distance[it]>distance[start]+1)
                {
                    distance[it]=distance[start]+1;
                }
                
            }
            
        }
        for(int i=0;i<N;i++)
        {
            if(distance[i]==100000)
            distance[i]=-1;
        }
        
        return distance;
        
        
    }
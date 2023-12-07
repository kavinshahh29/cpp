#include<bits/stdc++.h>
using namespace std;

// APPROACH USING BFS 

bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visit(V+1,false);
        queue<pair<int,int>>q;
        for(int i=0;i<V;i++)
        {
            if(visit[i]==0)
            {
                visit[i]=true;
                q.push({-1,i});
                while(!q.empty())
                {
                    int parent=q.front().first;
                    int child=q.front().second;
                    q.pop();
                    for(auto it:adj[child])
                    {
                        if(visit[it]==false)
                        {
                            q.push({child,it});
                            visit[it]=true;
                        }
                        else if(it!=parent)
                        return true;
                    }
                }
            }
        }
        return false;
    }

// APPROACH USING DFS 


 bool isCycle(int V, vector<int> adj[]) {
        
        vector<int>visit(V+1);
        int parent=-1;
        for(int i=0;i<V;i++)
        {
            if(visit[i]==0)
            {
                if(dfs(parent,i,adj,V,visit))
                return true;
            }
        }
        return false;
    }
    bool dfs(int parent,int start,vector<int>adj[],int V,vector<int>&visit)
    {
        visit[start]=1;
        for(auto it:adj[start])
        {
            if(visit[it]==0)
            {
                if(dfs(start,it,adj,V,visit)==true)
                return true;
            }
            else if(it!=parent)
            return true;
        }
        return false;
    }
#include<bits/stdc++.h>
using namespace std;

 void dfs(int start,int end,vector<int>&visit,vector<int>adj[],vector<int>&ans){
      visit[start]=1;
      ans.push_back(start);
      for(auto it:adj[start])
      {
          if(visit[it]==0)
          {
              dfs(it,end,visit,adj,ans);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    
          vector<int>visit(V,0);
          vector<int>ans;
          for(int i=0;i<V;i++)
          {
              if(visit[i]==0)
              dfs(i,V,visit,adj,ans);
          }
          return ans;
    }
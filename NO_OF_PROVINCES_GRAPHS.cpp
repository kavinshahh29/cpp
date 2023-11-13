// APPROACH -1 USING DFS 
#include<bits/stdc++.h>
using namespace std;
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
          vector<int>adja[V+1];
          for(int i=0;i<adj.size();i++)
          {
              for(int j=0;j<adj[i].size();j++)
              {
                  if(i!=j and adj[i][j]==1)
                  {
                      adja[i].push_back(j);
                      adja[j].push_back(i);
                      
                  }
              }
          }
          int count=0;
          vector<int>visit(V+1,0);
        //   visit[0]=1;
          for(int i=0;i<V;i++)
          {
              if(visit[i]==0)
              {
                  dfs(i,V,visit,adja);
                  count++;
              }
          }
          return count;
          
    }
    void dfs(int start,int end,vector<int>&visit,vector<int>adja[])
    {
        visit[start]=1;
        for(auto it:adja[start])
        {
            if(visit[it]==0)
            {
                dfs(it,start,visit,adja);
            }
        }
    }
};





// APPROACH -2 USINF BFS 

//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adja[V+1];
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(i!=j and adj[i][j]==1)
                {
                    adja[i].push_back(j);
                    adja[j].push_back(i);
                }
                
            }
        }
        int count=0;
        vector<bool>visit(V+1,false);
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(visit[i]==false)
            {
                q.push(i);
                count++;
                visit[i]=true;
                while(!q.empty())
                {
                    int temp=q.front();
                    q.pop();
                    for(auto it:adja[temp])
                    {
                        if(visit[it]==false)
                        {
                            q.push(it);
                            visit[it]=true;
                        }
                    }
                }
                
            }
        }
        
        

        return count;
        
        
    }
};

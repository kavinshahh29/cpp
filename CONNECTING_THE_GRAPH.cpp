#include<bits/stdc++.h>
using namespace std;


int Solve(int n, vector<vector<int>>& edges) {
          
          vector<int>parent(n);
          vector<int>rank(n,0);
          for(int i=0;i<n;i++)
          parent[i]=i;
          int c=0;
          for(int i=0;i<edges.size();i++)
          {
              int ulp_u=find(edges[i][0],parent);
              int ulp_v=find(edges[i][1],parent);
              if(ulp_u==ulp_v)
              c++;
              else
              {
                  if(rank[ulp_u]>rank[ulp_v])
                  {
                      parent[ulp_v]=ulp_u;
                  }
                  else if(rank[ulp_v]>rank[ulp_u])
                  {
                      parent[ulp_u]=ulp_v;
                  }
                  else
                  {
                      parent[ulp_u]=ulp_v;
                      rank[ulp_v]++;
                  }
              }
          }
          int cn=0;
          for(int i=0;i<n;i++)
          {
              if(find(i,parent)==i)
              cn++;
          }
          if(cn==1)
          return 0;
          
          int req=cn-1;
          if(c>=req)
          return req;
          return -1;
          
          
          
          
        
    }
    int find(int node,vector<int>&parent)
    {
        if(parent[node]==node)
        return node;
        
        return parent[node]=find(parent[node],parent);
    }
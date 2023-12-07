#include<bits/stdc++.h>
using namespace std;


class Disjoint{
    public:
    vector<int>rank,size,parent;
    
    Disjoint(int n)
    {
        parent.resize(n);
        size.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            size[i]=1;
            parent[i]=i;
        }
        
    }
    int find(int node)
    {
        if(parent[node]==node)
        return node;
        
        return parent[node]=find(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        
    }
    void unionbysize(int u,int v)
    {
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u==ulp_v){
          return;
        }
        
        
        if(size[ulp_u]>size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        
        
    }
};

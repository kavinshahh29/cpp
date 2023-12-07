#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>>ans(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i].first;
            int v=edges[i].second;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        return ans;
    }
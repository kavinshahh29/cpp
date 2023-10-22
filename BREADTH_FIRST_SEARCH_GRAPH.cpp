#include<bits/stdc++.h>
using namespace std;


vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       
        vector<int>ans;
        vector<int>visit(V,0);
        queue<int>q;
        q.push(0);
        visit[0]=1;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto it:adj[temp])
            {
                if(visit[it]==0)
                {
                    visit[it]=1;
                    q.push(it);
                }
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
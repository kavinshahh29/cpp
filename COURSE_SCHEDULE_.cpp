#include<bits/stdc++.h>
using namespace std;


vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<int>adj[n+1];
        for(int i=0;i<pre.size();i++)
        {
            int f=pre[i][0];
            int s=pre[i][1];
            adj[s].push_back(f);
            
        }
        vector<int>indegree(n+1,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int start=q.front();
            ans.push_back(start);
            q.pop();
            for(auto it:adj[start])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(ans.size()==n)
        return ans;
        ans.clear();
        return ans;
    }
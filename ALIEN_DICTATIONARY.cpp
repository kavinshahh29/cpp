#include<bits/stdc++.h>
using namespace std;


string findOrder(string dict[], int N, int k) {
        vector<int>adj[k+1];
        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<min(dict[i].length(),dict[i+1].length());j++)
            {
                if(dict[i][j]!=dict[i+1][j])
                {
                    adj[dict[i][j]-97].push_back(dict[i+1][j]-97);
                    break;
                }
            }
        }
        vector<bool>visit(k+1,false);
        stack<char>st;
        for(int i=0;i<k;i++)
        {
            if(visit[i]==false)
            {
                dfs(i,st,visit,adj);
            }
            
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            
        }
        return ans;
        
        
    }
    void dfs(int start,stack<char>&st,vector<bool>&visit,vector<int>adj[])
    {
        visit[start]=true;
        for(auto it:adj[start])
        {
            if(visit[it]==false)
            dfs(it,st,visit,adj);
        }
        char c=(char)(start+97);
        st.push(c);
        
    }

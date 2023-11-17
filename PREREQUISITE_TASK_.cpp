#include<bits/stdc++.h>
using namespace std;

bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    vector<int>adj[N+1];
	    for(int i=0;i<pre.size();i++)
	    {
	        int f=pre[i].first;
	        int s=pre[i].second;
	        adj[s].push_back(f);
	        
	        
	    }
	    vector<bool>visit(N+1,false);
	    vector<bool>pathvisit(N+1,false);
	    for(int i=0;i<N;i++)
	    
	    {
	        if(visit[i]==false)
	        {
	            
	            if(dfs(i,visit,pathvisit,adj)==true)
	            return false;
	        }
	    }
	    return true;
	    
	    
	    
	}
	bool dfs(int start,vector<bool>&visit,vector<bool>&pathvisit,vector<int>adj[])
	{
	    pathvisit[start]=true;
	    visit[start]=true;
	    
	    for(auto it:adj[start])
	    {
	        if(visit[it]==false)
	        {
	            if(dfs(it,visit,pathvisit,adj)==true)
	            return true;;
	        }
	        else if(pathvisit[it]==true)
	        return true;
	    }
	    pathvisit[start]=false;
	    return false;
	}
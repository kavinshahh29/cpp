#include<bits/stdc++.h<
using namespace std;

// USING  SIMPLE QUEUE


int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>>dist(N+1,vector<int>(N+1,INT_MAX));
	    vector<vector<bool>>visit(N+1,vector<bool>(N+1,false));
	   queue<pair<int,pair<int,int>>>pq;
	    dist[TargetPos[0]][TargetPos[1]]=0;
	    pq.push({0,{TargetPos[0],TargetPos[1]}});
	    int rowmatrix[]={-2,-2,2,2,-1,-1,1,1};
	    int colmatrix[]={-1,1,-1,1,-2,2,-2,2};
	    while(!pq.empty())
	    {
	        
	        int step=pq.front().first;
	        int row=pq.front().second.first;
	        int col=pq.front().second.second;
	       
	        pq.pop();
	        for(int i=0;i<8;i++)
	        {
	            int rowin=row+rowmatrix[i];
	            int colin=col+colmatrix[i];
	            if(rowin>=1 and rowin<N+1 and colin>=1 and colin<N+1 and dist[rowin][colin]>step+1)
	            {
	               
	                dist[rowin][colin]=step+1;
	               
	                pq.push({dist[rowin][colin],{rowin,colin}});
	            }
	            
	        }
	    }
	    if(dist[KnightPos[0]][KnightPos[1]]==INT_MAX)
	    return -1;
	    return dist[KnightPos[0]][KnightPos[1]];
	}


// USING PRIORITY QUEUE

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>>dist(N+1,vector<int>(N+1,INT_MAX));
	    vector<vector<bool>>visit(N+1,vector<bool>(N+1,false));
	    typedef pair<int,pair<int,int>>p;
	    priority_queue<p,vector<p>,greater<p>>pq;
	   
	    dist[TargetPos[0]][TargetPos[1]]=0;
	    pq.push({0,{TargetPos[0],TargetPos[1]}});
	    int rowmatrix[]={-2,-2,2,2,-1,-1,1,1};
	    int colmatrix[]={-1,1,-1,1,-2,2,-2,2};
	    while(!pq.empty())
	    {
	        
	        int step=pq.top().first;
	        int row=pq.top().second.first;
	        int col=pq.top().second.second;
	        pq.pop();
	        for(int i=0;i<8;i++)
	        {
	            int rowin=row+rowmatrix[i];
	            int colin=col+colmatrix[i];
	            if(rowin>=1 and rowin<N+1 and colin>=1 and colin<N+1 and dist[rowin][colin]>step+1)
	            {
	               
	                dist[rowin][colin]=step+1;
	              
	                pq.push({dist[rowin][colin],{rowin,colin}});
	            }
	            
	        }
	    }
	    if(dist[KnightPos[0]][KnightPos[1]]==INT_MAX)
	    return -1;
	    return dist[KnightPos[0]][KnightPos[1]];
	}



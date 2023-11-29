#include<bits/stdc++.h>
using namespace std;


int helpaterp(vector<vector<int>> hospital)
    {
        vector<vector<bool>>visit(hospital.size(),vector<bool>(hospital[0].size(),false));
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        
        int ans=0;
        queue<pair<int,pair<int,int>>>pq;
        
        for(int i=0;i<hospital.size();i++)
        {
            for(int j=0;j<hospital[0].size();j++)
            {
                if(hospital[i][j]==2)
                {
                    visit[i][j]=true;
                    pq.push({0,{i,j}});
                }
            }
        }
        pq.push({-1,{0,0}});
        while(!pq.empty())
        {
            int t=pq.front().first;
            int r=pq.front().second.first;
            int c=pq.front().second.second;
            pq.pop();
            if(t==-1)
            {
                if(!pq.empty())
                pq.push({-1,{0,0}});
            }
            else{
                 for(int i=0;i<4;i++)
                 {
                     int rowin=r+rowmatrix[i];
                     int colin=c+colmatrix[i];
                     if(rowin>=0 and rowin<hospital.size() and colin>=0 and colin<hospital[0].size() and visit[rowin][colin]==false and hospital[rowin][colin]==1)
                     {
                       pq.push({t+1,{rowin,colin}});
                       visit[rowin][colin]=true;
                     }
                     
                
                 }
                 ans=max(ans,t);
            
            }
            
        }
        for(int i=0;i<hospital.size();i++)
        {
            for(int j=0;j<hospital[0].size();j++)
            {
                if(hospital[i][j]==1 and visit[i][j]==false)
                return -1;
            }
        }
        return ans;
        
        
    }
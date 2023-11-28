#include<bits/stc++.h>
using namespace std;


// USING PRIORITY QUEUE
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(A[X][Y]==0)
        return -1;
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        
        typedef pair<int,pair<int,int>>p;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{X,Y}});
        dist[X][Y]=0;
        int rowm[]={0,-1,0,1};
        int colm[]={-1,0,1,0};
        while(!pq.empty())
        {
            int step=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int rowindex=rowm[i]+row;
                int colindex=colm[i]+col;
                if(rowindex>=0 and rowindex<A.size() and colindex>=0 and colindex<A[0].size() and A[rowindex][colindex]==1 and dist[rowindex][colindex]>step+1)
                {
                    dist[rowindex][colindex]=step+1;
                    pq.push({step+1,{rowindex,colindex}});
                }
            }
            
        }
        if(dist[0][0]==INT_MAX)
        return -1;
        return dist[0][0];
    }


// USING SIMPLE QUEUE



int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(A[X][Y]==0)
        return -1;
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        
    
        queue<pair<int,pair<int,int>>>pq;
       
        pq.push({0,{X,Y}});
        dist[X][Y]=0;
        int rowm[]={0,-1,0,1};
        int colm[]={-1,0,1,0};
        while(!pq.empty())
        {
            int step=pq.front().first;
            int row=pq.front().second.first;
            int col=pq.front().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int rowindex=rowm[i]+row;
                int colindex=colm[i]+col;
                if(rowindex>=0 and rowindex<A.size() and colindex>=0 and colindex<A[0].size() and A[rowindex][colindex]==1 and dist[rowindex][colindex]>step+1)
                {
                    dist[rowindex][colindex]=step+1;
                    pq.push({step+1,{rowindex,colindex}});
                }
            }
            
        }
        if(dist[0][0]==INT_MAX)
        return -1;
        return dist[0][0];
    }
#include<bits/stdc++.h>
using namespace std;


    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<int>>dist(M,vector<int>(N,-1));
        // Your code goes here
        vector<vector<bool>>visit(M,vector<bool>(N,false));
        queue<pair<int,int>>q;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][j]=='B')
                {
                    q.push({i,j});
                    dist[i][j]=0;
                    visit[i][j]=true;
                    
                }
            }
        }
        q.push({-2,-2});
        int c=1;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row==-2)
            {
                if(!q.empty())
                q.push({-2,-2});
                else
                return dist;
                c++;
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    int rowin=row+rowmatrix[i];
                    int colin=col+colmatrix[i];
                    if(rowin>=0 and rowin<M and colin>=0 and colin<N and visit[rowin][colin]==false and matrix[rowin][colin]!='W')
                    {
                        dist[rowin][colin]=c;
                        q.push({rowin,colin});
                        visit[rowin][colin]=true;
                        
                    }
                }
                
            }
            
        }
        return dist;
    } 
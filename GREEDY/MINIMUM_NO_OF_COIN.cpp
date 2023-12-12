#include<bits/stdc++.h>
using namespace std;


vector<int> minPartition(int N)
    {
        priority_queue<int>pq;
        pq.push(2000);
        pq.push(500);
        pq.push(200);
        pq.push(100);
        pq.push(50);
        pq.push(20);
        pq.push(10);
        pq.push(5);
        pq.push(2);
        pq.push(1);
        int req=0;
        vector<int>ans;
        while(!pq.empty() and req<N)
        {
            int t=pq.top();
            pq.pop();
            if(req+t>N)
            continue;

            int x=(N-req)/t;
            req=req+x*t;
            
            for(int i=0;i<x;i++)
            {
                ans.push_back(t);
            }
            
            
        }
        return ans;
    }
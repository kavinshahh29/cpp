#include<bits/stdc++.h>
using namespace std;





int maxMeetings(int start[], int end[], int n)
    {
        typedef pair<int,int>p;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<n;i++)
        pq.push({end[i],start[i]});
        
        int count=0;
        int req=-1;
        while(!pq.empty())
        {
            int e=pq.top().first;
            int s=pq.top().second;
            pq.pop();
            if(s>req)
            {
                req=e;
                count++;
            }
        }
        return count;
    }



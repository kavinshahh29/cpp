#include<bits/stdc++.h>
using namespace std;


 double fractionalKnapsack(int W, Item arr[], int n)
    {
        double profit=0;
        typedef pair<double,pair<int,int>>p;
        priority_queue<p>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({(arr[i].value*1.0)/arr[i].weight,{arr[i].value,arr[i].weight}});
            
        }
        
        vector<double>solution(n,0);
        double cap=0;
        int i=0;
        while(!pq.empty() and cap<W)
        {
            double r=pq.top().first;
            double v=pq.top().second.first;
            double wt=pq.top().second.second;
            pq.pop();
            if(cap+wt<=W)
            {
                solution[i]=1;
            }
            else
            {
                solution[i]=(W-cap)/wt;
                
            }
            profit=profit+solution[i]*v;
            cap=cap+solution[i]*wt;
            i++;
            
        }
        return profit;
    }
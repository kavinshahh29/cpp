#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>&q,int&k,queue<int>&ans)
{
    if(q.empty() || k==0)
    {
        return;
    }
    int t=q.front();
    q.pop();
    k--;
    reverse(q,k,ans);
    ans.push(t);
}
queue<int> modifyQueue(queue<int> q, int k) {
    queue<int>ans;
       reverse(q,k,ans);
       while(!q.empty())
       {
           ans.push(q.front());
           q.pop();
       }
       return ans;
}
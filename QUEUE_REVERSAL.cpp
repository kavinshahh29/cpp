#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int>&q)
    {
        if(q.empty())
        {
            return;
            
        }
        int a=q.front();
        q.pop();
        reverse(q);
        q.push(a);
    }
    queue<int> rev(queue<int> q)
    {
        
        reverse(q);
        return q;
    }



#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&st,int X)
   {
       if(st.empty())
       {
           st.push(X);
           return;
       }
       int t=st.top();
       st.pop();
       solve(st,X);
       st.push(t);
   }
    stack<int> insertAtBottom(stack<int> St,int X){
        solve(St,X);
        return St;
        
    }
#include<bits/stdc++.h>
using namespace std;
 void insertatbottom(stack<int>&st,int x)
  {
      if(st.empty())
      {
          st.push(x);
          return;
      }
      int t=st.top();
      st.pop();
      insertatbottom(st,x);
      st.push(t);
  }
    void Reverse(stack<int> &St){
        
        if(St.empty() || St.size()==1)
        return ;
       
        int num=St.top();
        St.pop();
        Reverse(St);
        
        insertatbottom(St,num);
            
        
    }
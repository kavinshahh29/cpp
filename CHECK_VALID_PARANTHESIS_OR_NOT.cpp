#include<bits/stdc++.h>
using namespace std;
   bool ispar(string s)
    {
        // Your code here
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                
            }
            else
            {
                if(!st.empty())
                {
                    if((st.top()=='(' and s[i]==')' )|| (st.top()=='['  and s[i]==']') || (st.top()=='{' and s[i]=='}'))
                    {
                        
                        st.pop();
                        
                    }
                    else{
                        
                        return false;
                    }
                    
                        
                }
                
                 else
                return false;
            }
               
        }
    
        if(st.empty()==1)
        return true;
        return false;
    }

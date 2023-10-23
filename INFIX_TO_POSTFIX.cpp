#include<bits/stdc++.h>
using namespace std;
 int precedence_check(char a)
    {
        if(a=='+' || a=='-')
        return 2;
        else if(a=='/' || a=='*')
        return 3;
        else if(a=='^')
        return 4;
        return 1;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]=='(')
            st.push(s[i]);
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if(!st.empty() and precedence_check(s[i])<=precedence_check(st.top()))
                {
                    while(!st.empty() and (precedence_check(st.top())>=precedence_check(s[i])))
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    
                    
                    
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
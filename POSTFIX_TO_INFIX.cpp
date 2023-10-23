#include<bits/stdc++.h>
using namespace std;

string postToInfix(string exp) {
        
        stack<string>st;
        for(int i=0;i<exp.length();i++)
        {
            if((exp[i]>='A' and exp[i]<='Z') or (exp[i]>='a' and exp[i]<='z'))
            {
                string str(1,exp[i]);
                st.push(str);
            }
            else
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                
                st.push("("+b+exp[i]+a+")");

            }
        }
        return st.top();
    }
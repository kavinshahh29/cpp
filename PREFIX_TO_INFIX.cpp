#include<bits/stdc++.h>
using namespace std;
string preToInfix(string str) {
        
        reverse(str.begin(),str.end());
        stack<string>st;
        for(int i=0;i<str.length();i++)
        {
            if((str[i]>='A' and str[i]<='Z') or (str[i]>='a' and str[i]<='z'))
            {
                string temp(1,str[i]);
                st.push(temp);
            }
            else
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                st.push("(" + a+str[i]+b+")");
            }
        }
        return st.top();
    }
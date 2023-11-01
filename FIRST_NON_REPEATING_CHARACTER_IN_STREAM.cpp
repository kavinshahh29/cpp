#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		  
		    queue<char>q;
		    string ans="";
		    map<char,int>mp;
		    for(int i=0;i<A.length();i++)
		    {
		        q.push(A[i]);
		        mp[A[i]]++;
		        while(!q.empty() and mp[q.front()]!=1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		        {
		            ans+='#';
		        }
		        else
		        {
		            ans+=q.front();
		        }
		    }
		    return ans;
		}

};
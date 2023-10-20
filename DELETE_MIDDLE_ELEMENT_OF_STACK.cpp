
#include <bits/stdc++.h> 
using namespace std;
void solve(stack<int>&st,int n,int &c)
{
   if(c==n/2){
   st.pop();
   return;
   }
   int x=st.top();
   st.pop();
   c++;
   solve(st,n,c);
   st.push(x);
   
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
   solve(inputStack,N,count);
   
}
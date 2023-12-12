#include<bits/stdc++.h>
using namespace std;

void fun(int n,int &count)
{
    if(count>n)
    return;
    cout<<count<<endl;
    count++;
    fun(n,count);
}
void fun2(int i,int n)
{
    if(i==0)
    return;

    fun2(i-1,n);
    cout<<i<<endl;
}
int main()
{
    int n;
    cin>>n;
    int count=1;
    fun(n,count);

    int i=n;
   cout<<"using backtracking"<<endl;
    fun2(i,n);
}
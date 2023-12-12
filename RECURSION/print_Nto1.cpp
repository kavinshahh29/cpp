#include<bits/stdc++.h>
using namespace std;

void fun(int &n)
{
    if(n==0)
    return;
    cout<<n<<endl;
    n--;
    fun(n);
}
void fun2(int i,int n)
{
    if(i>n)
    return;
    fun2(i+1,n);
    cout<<i<<endl;
}
int main()
{
    int n;
    cin>>n;
    int i=0;
    int a=n;
    fun(a);
  
    cout<<"backtrack using"<<endl;
    fun2(i+1,n); // using backtrack
}




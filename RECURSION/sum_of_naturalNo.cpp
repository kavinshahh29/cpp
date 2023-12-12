#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(n==0)
    return 0;
    return n+sum(n-1);
}
int sum2(int i,int n)
{
    if(i>n)
    return 0;

    return i+sum2(i+1,n);

}
int main()
{
    int n;
    cout<<"ENTER THE NUMBER"<<endl;
    cin>>n;

    cout<<sum(n)<<endl;  // using functional recursion with returning values
    int i=1;
     cout<<sum2(i,n)<<endl;

}

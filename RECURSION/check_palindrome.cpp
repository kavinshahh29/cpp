#include<bits/stdc++.h>
using namespace std;

bool check(string str,int i)
{
    if(i>=str.length()/2)
    return true;

    if(str[i]!=str[str.length()-i-1])
    return false;
    return check(str,i+1);
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    cin>>str;
    int n=str.length();
    cout<<check(str,0)<<endl;
}
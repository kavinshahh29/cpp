#include<bits/stdc++.h>
using namespace std;

void name_print(string name,int &count)
{
    if(count==0)
    return;
    count--;
    cout<<name<<endl;
    name_print(name,count);
}
int main()
{
    string name;
    cout<<"ENTER YOUR NAME ";
    cin>>name;

   int count;
   cout<<"HOW MANY TIMES U WANT TO PRINT YOUR NAME ? ";
   cin>>count;
    name_print(name,count);

}
#include<bits/stdc++.h>
using namespace std;

void subset(int index,int arr[],int n,vector<vector<int>>&ans,vector<int>temp)
{
    if(index>=n)
    {
        ans.push_back(temp);
        return;
    }
    subset(index+1,arr,n,ans,temp);
    temp.push_back(arr[index]);
    
    subset(index+1,arr,n,ans,temp);
    temp.pop_back();


    

}
int main()
{
    int arr[3]={1,2,3};
    vector<vector<int>>ans;
    vector<int>temp;
    subset(0,arr,3,ans,temp);

    for(int i=0;i<ans.size();i++)
    {
        cout<<"{";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<",";
        }
        cout<<"}"<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int n,int start,int end)
{
    if(start>=end)
    return;
    swap(arr[start],arr[end]);
    reverse(arr,n,start+1,end-1);
    
}
void reverse2(int arr[],int n,int i)
{
        if(i>=n/2)
        return;
        swap(arr[n-i-1],arr[i]);
        reverse2(arr,n,i+1);

    
   

}
int main()
{
    int n;
    cout<<"ENTER THE SIZE OF ARRAY"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    


    reverse(arr,n,0,n-1);
        for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    reverse2(arr,n,0);
          for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
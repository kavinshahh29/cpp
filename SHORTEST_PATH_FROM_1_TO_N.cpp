#include<bits/stdc++.h>
using namespace std;


    int minimumStep(int n){
      if(n==1)
      return 0;
      
        int ans=0;
        check(n,ans);
        return ans;
    }
    void check(int &n,int&ans)
    {
        if(n<=1)
        return;
        else if(n%3==0)
        {
            ans+=1;
            n=n/3;
            check(n,ans);
        }
        else
        {
            ans+=1;
            n--;
            check(n,ans);
        }
    }

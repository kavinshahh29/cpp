#include<bits/stdc++.h>
using namespace std;
 int nthFibonacci(int n){
        int fib[n+1];
        fib[0]=0;
        fib[1]=1;
        for(int i=2;i<=n;i++)
        {
            fib[i]=(fib[i-1]+fib[i-2])%1000000007;
        }
        return fib[n];

    }

// USING RECURSION -- BRUTE FORCE APPROACH

int nthFibonacci(int n){
        
        if (n<=1)
            return n;
        return nthFibonacci(n-1)+nthFibonacci(n-2);
}
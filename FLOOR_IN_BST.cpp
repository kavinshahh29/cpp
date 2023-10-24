#include<bits/stdc++.h>
using namespace std;

void solve(Node*root,int x,int &ans){
        if(root==nullptr)
        return;
        solve(root->left,x,ans);
        if(x>=root->data)
        ans=root->data;
        solve(root->right,x,ans);
    }
    int floor(Node* root, int x) {
        
        int ans=-1;
        solve(root,x,ans);
        return ans;
    }
#include<bits/stdc++.h>
using namespace std;
void preorder(Node*root,vector<int>&ans)
{
    if(root==nullptr)
    return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
vector <int> preorder(Node* root)
{
  // Your code here
  
  vector<int>ans;
     preorder(root,ans);
     return ans;
  
}

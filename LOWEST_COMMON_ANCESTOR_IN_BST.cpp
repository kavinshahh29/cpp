#include<bits/stdc++.h>
using namespace std;
// APPROACH 1
void solve(Node*root,int n1,int n2,Node*&ans)
        {
            if(root==nullptr)
            return;
            // cout<<"HELLO";
            solve(root->left,n1,n2,ans);
            if(root->data>=n1 and root->data<=n2)
            {
                // cout<<"helo";
                ans=root;
                return;
            }
            // cout<<"HELLO";
            solve(root->right,n1,n2,ans);
            
        }
        Node* LCA(Node *root, int n1, int n2)
        {
            if(n1<root->data and n2>root->data)
            return root;
            else if(n2<root->data and n1>root->data)
            return root;
            else
            {
                Node*ans=new Node(0);
                int a1=min(n1,n2);
                int a2=max(n1,n2);
                  solve(root,a1,a2,ans);
                  return ans;

            }
            
        }
    // APPROACH 2 (RECURSION)

       Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(root==nullptr)
            return NULL;
            else if(root->data<n1 and root->data<n2)
            {
                return LCA(root->right,n1,n2);
            }
            else if(root->data>n1 and root->data>n2)
            return LCA(root->left,n1,n2);
            return root;
        }

#include<bits/stdc++.h>
using namespace std;
vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int t=INT_MIN;
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp==nullptr)
            {
                ans.push_back(t);
                t=INT_MIN;
                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                t=max(t,temp->val);
                if(temp->left!=nullptr)
                q.push(temp->left);
                if(temp->right!=nullptr)
                q.push(temp->right);
            }
            
        }
        return  ans;
         
    }
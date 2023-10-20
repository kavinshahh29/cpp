#include<bits/stdc++.h>
using namespace std;
vector<int> rightView(Node *node)
    {
       // Your Code here
       vector<int>ans;
          if(node==nullptr)
          return ans;
          vector<int>res;
          queue<Node*>q;
          q.push(node);
          q.push(NULL);
          while(!q.empty())
          {
              Node*temp=q.front();
              q.pop();
              if(temp==nullptr)
              {
                  res.push_back(ans[0]);
                  ans.clear();
                  if(!q.empty())
                  q.push(NULL);
              }
              else
              {
                  if (temp->right)
                  q.push(temp->right);
                  if(temp->left!=nullptr)
                  q.push(temp->left);
                   
                  ans.push_back(temp->data);
              }
          }
          return res;
    }
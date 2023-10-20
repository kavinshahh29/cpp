#include<bits/stdc++.h>
using namespace std;
 vector <int> zigZagTraversal(Node* node)
    {
    	// Code here
    	vector<int>ans;
          if(node==nullptr)
          return ans;
          int count=0;
          queue<Node*>q;
          q.push(node);
          q.push(NULL);
          vector<int>res;
          while(!q.empty())
          {
              Node*temp=q.front();
              q.pop();
              if(temp==nullptr)
              {
            
                  if(count%2==0){
                  for(int i=0;i<ans.size();i++)
                  res.push_back(ans[i]);
                  }
                  else
                  {
                      for(int i=ans.size()-1;i>=0;i--)
                      res.push_back(ans[i]);
                  }
                  count++;
                  ans.clear();
                  if(!q.empty())
                  q.push(NULL);
              }
              else
              {
                  
                  if(temp->left!=nullptr)
                  q.push(temp->left);
                  if(temp->right)
                  q.push(temp->right);
                  
                  
                   ans.push_back(temp->data);
               }
          
          }
          return res;
    }
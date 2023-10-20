vector<int> levelOrder(Node* node)
    {
      //Your code here
          vector<int>ans;
          if(node==nullptr)
          return ans;
          queue<Node*>q;
          q.push(node);
          q.push(NULL);
          while(!q.empty())
          {
              Node*temp=q.front();
              q.pop();
              if(temp==nullptr)
              {
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
          return ans;
    }
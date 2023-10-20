vector<int> preOrder(Node* root)
    {
        
       vector<int>ans;
       if(root==nullptr)
       return ans;
       stack<Node*>st;
       st.push(root);
       while(!st.empty())
       {
           Node*temp=st.top();
           st.pop();
           if(temp->right!=nullptr)
           st.push(temp->right);
           if(temp->left!=nullptr)
           st.push(temp->left);
           ans.push_back(temp->data);
       }
       return ans;
    }
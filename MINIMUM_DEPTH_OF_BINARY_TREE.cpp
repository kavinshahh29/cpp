  // APPRAOACH -1 RECURSIVE
  int solve(Node*root)
  {
      if(root==nullptr)
      return 0;
        if(root->left==nullptr)
      return solve(root->right)+1;
      
      if(root->right==nullptr)
      return solve(root->left)+1;
      int lh=solve(root->left);
      int rh=solve(root->right);
    
      return min(lh,rh)+1;
      
  }
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        // Your code here\
        
        return solve(root);
    }



    // APPROACH-2 ITERATIVE [LEVEL ORDER TRAVERSAL]
    int minDepth(Node *root) {
        // Your code here
        if(root==nullptr)
        return 0;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        int count=0;
        while(!q.empty())
        {
            Node*temp=q.front();
            q.pop();
            if(temp==nullptr)
            {
                count++;
                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                if(temp->left!=nullptr)
                q.push(temp->left);
                if(temp->right!=nullptr)
                q.push(temp->right);
                if(temp->left==nullptr and temp->right==nullptr)
                return count+1;
                
            }
            
            
        }
        return 0;
    }
// APPROACH 1

pair<bool,int>solve(Node*root)
    {
        if(root==nullptr)
        {
            return{true,0};
        }
        if(root->left==nullptr and root->right==nullptr)
        {
            return{true,root->data};
        }
        pair<bool,int>leftsubtree=solve(root->left);
        pair<bool,int>rightsubtree=solve(root->right);
        if(leftsubtree.first==true and rightsubtree.first==true and leftsubtree.second+rightsubtree.second==root->data){
              
              return{true,2*root->data};
        }
        else
        {
            return{false,0};
        }
        return{true,0};
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==nullptr)
         return true;
         return solve(root).first;
    }

// APPROACH 2

 int f=1;
    int check(Node*root)
    {
        if(root==nullptr)
        return 0;
        if(root->left==nullptr && root->right==nullptr)
        return root->data;
        if(f==0)
        return 0;
        int a=check(root->left);
        int b=check(root->right);
        if(a+b!=root->data) f=0;
        
        return a+b+root->data;
        
        
      
    }
    bool isSumTree(Node* root)
    {
         // Your code here
          
          
          check(root);
          return f;
         
        
         
    }
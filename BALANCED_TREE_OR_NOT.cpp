  int solve(Node*root,bool &ans){
        if(root==nullptr)
        return 0;
        int lh=solve(root->left,ans);
        int rh=solve(root->right,ans);
        if(abs(lh-rh)>1)
        ans=false;
        return max(lh,rh)+1;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        
        if(root==nullptr)
        return true;
        bool ans=true;
        solve(root,ans);
        return ans;
    }
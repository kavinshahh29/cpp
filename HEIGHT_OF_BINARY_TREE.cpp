 int solve(struct Node*node)
    {
        if(node==nullptr)
        return 0;
        int lh=solve(node->left);
        int rh=solve(node->right);
        return max(lh,rh)+1;
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        return solve(node);
    }
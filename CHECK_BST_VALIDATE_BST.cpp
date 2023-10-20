bool check(Node*root,int min,int max)
    {
        if(root==nullptr)
        return true;
        if(root->data<max and root->data>min)
        {
            if(check(root->left,min,root->data)==false)
            return false;
            if(check(root->right,root->data,max)==false)
            return false;
        
            
        }
        else
        return false;
        
        return true;
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        int maxi=INT_MAX;
        int mini=INT_MIN;
        if(root==nullptr)
        return true;
        int a=check(root->left,INT_MIN,root->data);
        int b=check(root->right,root->data,INT_MAX);
        return (a==true and b==true);
    }
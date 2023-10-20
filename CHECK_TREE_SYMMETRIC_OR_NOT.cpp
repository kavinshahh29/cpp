 bool checkidentical(struct Node*r1,struct Node*r2)
    {
        if(r1==nullptr || r2==nullptr)
        return r1==r2;
        return checkidentical(r1->left,r2->right) and checkidentical(r1->right,r2->left) and r1->data==r2->data;
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==nullptr)
	    return true;
	    return checkidentical(root->left,root->right);
    }
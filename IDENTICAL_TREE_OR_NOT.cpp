bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==nullptr || r2==nullptr)
        return r1==r2;
        
        return isIdentical(r1->left,r2->left) and isIdentical(r1->right,r2->right) and r1->data==r2->data;
    }
  void inorderpre(Node*root,Node*&pre,int key)
    {
        if(root==nullptr)
        {
            return;
        }
        inorderpre(root->left,pre,key);
        if(root->key<key)
        {
            pre=new Node(root->key);
        }
        else
        return;
        inorderpre(root->right,pre,key);
    }
    void inordersuc(Node*root,Node*&suc,int key)
    {
        if(root==nullptr)
        return;
        inordersuc(root->right,suc,key);
        if(root->key>key)
        {
            suc=new Node(root->key);
            
        }
        inordersuc(root->left,suc,key);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=nullptr;
        inorderpre(root,pre,key);
        
        inordersuc(root,suc,key);
    
    }
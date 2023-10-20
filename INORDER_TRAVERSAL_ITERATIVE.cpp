 vector<int> inOrder(Node* root)
    {
        vector<int>ans;
        if(root==nullptr)
        return ans;
        stack<Node*>st;
        Node*cur=root;
        while(cur!=nullptr|| !st.empty())
        {
            while(cur!=nullptr)
            {
                st.push(cur);
                cur=cur->left;
                
            }
            Node*temp=st.top();
            cur=temp->right;
            ans.push_back(temp->data);
            st.pop();
        }
        return ans;
        
        //code here
    }
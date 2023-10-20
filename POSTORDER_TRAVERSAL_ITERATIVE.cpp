vector<int> postOrder(Node* node) {
        // code here
        vector<int>ans;
        if(node==nullptr)
        return ans;
        stack<Node*>st;
        stack<int>a;
        st.push(node);
        while(!st.empty())
        {
            Node*temp=st.top();
            st.pop();
            if(temp->left!=nullptr)
            st.push(temp->left);
            if(temp->right!=nullptr)
            st.push(temp->right);
            a.push(temp->data);
            
        }
        while(!a.empty())
        {
            ans.push_back(a.top());
            a.pop();
        }
        return ans;
    }
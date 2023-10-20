void solve(Node*root,int &k,int &ans)
  {
      if(root==nullptr || k<1)
      return;
      solve(root->left,k,ans);
      
      if(k==1)
      ans=root->data;
      k--;
      solve(root->right,k,ans);
  }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int ans=-1;
        solve(root,K,ans);
        return ans;
        
    }
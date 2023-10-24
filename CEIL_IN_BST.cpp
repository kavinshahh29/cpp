void solve(Node*root,int input,int&ans){
    if(root==nullptr)
    return;
    solve(root->right,input,ans);
    if(input<=root->data)
    ans=root->data;
    solve(root->left,input,ans);
}

int findCeil(Node* root, int input) {
    int ans=-1;
    solve(root,input,ans);
    return ans;

    // Your code here
}

void inorder(TreeNode *root, vector<int> &in) {
    if(!root) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> res;
    inorder(A, res);
    // sort(res.begin(), res.end());
    return res[B-1];
}
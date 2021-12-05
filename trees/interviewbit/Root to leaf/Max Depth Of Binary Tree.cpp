int maxDepthHelper(TreeNode* root, int maxi) {
    if(!root) return 0;
    int left = maxDepthHelper(root->left, maxi);
    int right = maxDepthHelper(root->right, maxi);
    return max(left, right) + 1;
}
int Solution::maxDepth(TreeNode* A) {
    return maxDepthHelper(A, 0);
}

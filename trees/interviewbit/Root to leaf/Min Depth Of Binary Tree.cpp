int minDepthHelper(TreeNode* root, int depth) {
    if(!root) return INT_MAX;
    if(!root->left && !root->right) return depth+1;
    int left = minDepthHelper(root->left, depth);
    int right = minDepthHelper(root->right, depth);
    return min(left, right) + 1;
}
int Solution::minDepth(TreeNode* A) {
    return minDepthHelper(A, 0);
}

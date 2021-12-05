int hasPathSumHelper(TreeNode* root, int target) {
    if(!root) return false;
    if(!root->left && !root->right) {
        if(target-root->val == 0) return true;
        else return false;
    }
    bool left = hasPathSumHelper(root->left, target-root->val);
    bool right = hasPathSumHelper(root->right, target-root->val);
    return left || right;
}  
int Solution::hasPathSum(TreeNode* A, int B) {
    return hasPathSumHelper(A, B);
}

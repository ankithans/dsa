int sumNumbersHelper(TreeNode* root, int s) {
    if(!root) return 0;
    s = (s*10 + root->val)%1003;
    if(!root->left && !root->right) return s;
    return sumNumbersHelper(root->left, s) + sumNumbersHelper(root->right, s);
}
int Solution::sumNumbers(TreeNode* A) {
    return sumNumbersHelper(A, 0) % 1003;
}

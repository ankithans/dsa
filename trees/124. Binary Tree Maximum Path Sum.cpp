class Solution {
public:
    int maxPathSumUtil(TreeNode* root, int &ans) {
        if(!root) return 0;
        
        int left = maxPathSumUtil(root->left, ans);
        int right = maxPathSumUtil(root->right, ans);
        
        int leftrightmax = max(left, right);
        int onenoderootmax = max(root->val, root->val + leftrightmax);
        int maxall = max(onenoderootmax, root->val + left + right);

        ans = max(ans, maxall);
        
        return onenoderootmax;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSumUtil(root, ans);
        return ans;
    }
};
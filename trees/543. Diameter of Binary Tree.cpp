// what if we calculate the height of the tree while maintaining the diameter
class Solution {
public:
    int dfs(TreeNode *root, int &dia) {
        if(!root) return 0;
        
        int leftDepth = dfs(root->left, dia);
        int rightDepth = dfs(root->right, dia);
        
        dia = max(dia, leftDepth + rightDepth);
        
        return 1 + max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia  = 0;
        dfs(root, dia);
        return dia;
    }
};


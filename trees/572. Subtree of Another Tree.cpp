// inspired from sameTree
class Solution {
public:
    bool isSame(TreeNode *t1, TreeNode *t2) {
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        if(t1->val != t2->val) return false;
        
        return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSame(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
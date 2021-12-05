
void inorder(TreeNode *root, vector<int> &in) {
    if(!root) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}
int Solution::t2Sum(TreeNode* root, int target) {
    vector<int> tree;
    inorder(root, tree);
    
    unordered_set<int> set;
    for(int i = 0; i < tree.size(); i++) {
        if(set.find(target-tree[i]) != set.end()) return 1;
        set.insert(tree[i]);
    }
    return 0;
}
void inorder(TreeNode *root, vector<int> &res, TreeNode* &prev) {
    if(!root) return;
    inorder(root->left, res, prev);

    if(prev && prev->val > root->val) {
        res.push_back(root->val);
        res.push_back(prev->val);
        // return;
    } 
    prev = root;

    inorder(root->right, res, prev);
}
vector<int> Solution::recoverTree(TreeNode* root) {
    vector<int> res;
    TreeNode* prev = nullptr;
    inorder(root, res, prev);
    sort(res.begin(), res.end());
    return {res[0], res[res.size()-1]};
}







void inorder(TreeNode *root, TreeNode* &first, TreeNode* &middle, TreeNode* &prev, TreeNode* &last) {
    if(!root) return;
    inorder(root->left, first, middle, prev, last);

    if(prev && prev->val > root->val) {

        // if first violation
        if(!first) {
            first = prev;
            middle = root;
        } 
        // if second violation
        else {
            last = root;
        }
    } 
    prev = root;

    inorder(root->right, first, middle, prev, last);
}
vector<int> Solution::recoverTree(TreeNode* root) {
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* prev = nullptr;
    TreeNode* last = nullptr;
    inorder(root, first, middle, prev, last);

    if(first && last) return {last->val, first->val};
    else return {middle->val, first->val};
}

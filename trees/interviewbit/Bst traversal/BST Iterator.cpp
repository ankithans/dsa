// first push the left side
// when left side vanished then push left side of right side
// https://leetcode.com/problems/binary-search-tree-iterator/discuss/1430547/C%2B%2B-Simple-Solution-using-Stack-O(h)-Time-Complexity-(-with-Diagrammatic-Explanation-)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> st;
void partialInorder(TreeNode *root) {
    while(root != nullptr) {
        st.push(root);
        root = root->left;
    }
}
BSTIterator::BSTIterator(TreeNode *root) {
    partialInorder(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *top = st.top();
    st.pop();
    partialInorder(top->right);
    return top->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

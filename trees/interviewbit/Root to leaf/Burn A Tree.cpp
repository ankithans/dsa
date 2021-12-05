int findMaxDistance(unordered_map<TreeNode*, TreeNode*> &parentMap, TreeNode* target) {
    queue<TreeNode*> q;
    q.push(target);
    unordered_map<TreeNode*, int> visited;
    visited[target] = 1;
    int maxi = 0;
    while(!q.empty()) {
        int size = q.size();
        int flag = 0;

        for(int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            
            if(parentMap[curr] && !visited[parentMap[curr]]) {
                flag = 1;
                visited[parentMap[curr]] = 1;
                q.push(parentMap[curr]);
            }
            if(curr->left && !visited[curr->left]) {
                flag = 1;
                visited[curr->left] = 1;
                q.push(curr->left);
            }
            if(curr->right && !visited[curr->right]) {
                flag = 1;
                visited[curr->right] = 1;
                q.push(curr->right);
            }
        }
        if(flag) maxi++;
    }
    return maxi;
}
TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap, int start) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()) {
        TreeNode* curr = q.front();
        if(curr->val == start) res = curr;
        q.pop();

        if(curr->left) {
            parentMap[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right) {
            parentMap[curr->right] = curr;
            q.push(curr->right);
        }
    }
    return res;
}
int Solution::solve(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    TreeNode* target = bfsToMapParents(root, parentMap, start);
    int maxi = findMaxDistance(parentMap, target);
    return maxi;
}

// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};

// bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);
        
        while(!q.empty()) {
            count++;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode *curr = q.front(); 
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return count;
    }
};
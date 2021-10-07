// dfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        return (l == 0 || r == 0) ? 1 + max(l,r) : 1 + min(l, r);
    }
};

// bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            level++;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode *curr = q.front();
                q.pop();
                
                if(!curr->left && !curr->right) return level;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return level;
    }
};
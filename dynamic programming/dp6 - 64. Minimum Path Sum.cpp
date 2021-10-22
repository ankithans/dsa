class Solution {
public:
    int mpsHelper(vector<vector<int>> &grid, int i, int j) {
        if(i >= grid.size() || j >= grid[i].size()) return INT_MAX;
        if(i == grid.size()-1 && j == grid[i].size()-1) return grid[i][j];
        
        int down = INT_MAX, right = INT_MAX;
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) {
            down = mpsHelper(grid, i+1, j);
            right = mpsHelper(grid, i, j+1);
        }
        
        return grid[i][j] + min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return mpsHelper(grid, 0, 0);
    }
};


class Solution {
public:
    vector<vector<int>> dp;
    int mpsHelper(vector<vector<int>> &grid, int i, int j) {
        if(i >= grid.size() || j >= grid[i].size()) return INT_MAX;
        if(i == grid.size()-1 && j == grid[i].size()-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = INT_MAX, right = INT_MAX;
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) {
            down = mpsHelper(grid, i+1, j);
            right = mpsHelper(grid, i, j+1);
        }
        
        return dp[i][j] = grid[i][j] + min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size()+1, vector<int>(grid.size()+1, -1));
        return mpsHelper(grid, 0, 0);
    }
};
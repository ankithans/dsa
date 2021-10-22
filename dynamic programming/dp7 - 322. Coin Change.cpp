class Solution {
public:
    int ccHelper(vector<int> &coins, int ind, int amount) {
        if(ind >= coins.size() || amount < 0) return INT_MAX-1;
        if(amount == 0) return 0;
        
        int pick = INT_MAX;
        int not_pick = INT_MAX;
        if(coins[ind] <= amount) {
            pick = 1 + ccHelper(coins, ind, amount-coins[ind]);
        }
        not_pick = ccHelper(coins, ind+1, amount);
        
        return min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = ccHelper(coins, 0, amount); 
        return ans == INT_MAX-1 ? -1 : ans;
    }
};

class Solution {
public:
    vector<vector<int>> dp;
    int ccHelper(vector<int> &coins, int ind, int amount) {
        if(ind >= coins.size() || amount < 0) return INT_MAX-1;
        if(amount == 0) return 0;
        
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int pick = INT_MAX;
        int not_pick = INT_MAX;
        if(coins[ind] <= amount) {
            pick = 1 + ccHelper(coins, ind, amount-coins[ind]);
        }
        not_pick = ccHelper(coins, ind+1, amount);
        
        return dp[ind][amount] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+1, vector<int>(amount+1, -1));
        int ans = ccHelper(coins, 0, amount); 
        return ans == INT_MAX-1 ? -1 : ans;
    }
};
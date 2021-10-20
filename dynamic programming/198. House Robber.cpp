// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// police will be alerted only if theive robs adjacent two houses

// recursive - TLE
class Solution {
public:
    int robHelper(vector<int> &nums, int index, int flag) {
        if(index == nums.size()) return 0;
        
        int maxi = INT_MIN;
        if(flag == 0) {
            maxi = max(nums[index]+robHelper(nums, index+1, 1), robHelper(nums, index+1, 0));
        } else {
            maxi = robHelper(nums, index+1, 0);
        }
        
        return maxi;
    }
    int rob(vector<int>& nums) {
        return robHelper(nums, 0, 0);
    }
};


// memoisation
class Solution {
public:
    int robHelper(vector<int> &nums, int index, int flag, vector<vector<int>> &dp) {
        if(index == nums.size()) return 0;
        
        if(dp[index][flag] != -1) return dp[index][flag];
        
        int maxi = INT_MIN;
        if(flag == 0) {
            maxi = max(nums[index]+robHelper(nums, index+1, 1, dp), robHelper(nums, index+1, 0, dp));
        } else {
            maxi = robHelper(nums, index+1, 0, dp);
        }
        
        return dp[index][flag] = maxi;
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(2, -1));
        return robHelper(nums, 0, 0, dp);
    }
};


// dp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        for(int i = n-1; i >= 0; i--) {
            dp[i][0] = max(nums[i]+dp[i+1][1], dp[i+1][0]);
            dp[i][1] = dp[i+1][0];
        }
        
        return max(dp[0][0], dp[0][1]);
    }
};
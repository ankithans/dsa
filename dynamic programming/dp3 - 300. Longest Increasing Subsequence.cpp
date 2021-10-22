//  0  1 2 3 4 5  6  7
// [10,9,2,5,3,7,101,18]
// o/p = 4     [2,3,7,101]

// idx -> f -> LIS

//                         (0, [])
//             2   (1, [10])                               (1, [])
//             (2,[10])                              (2,[9])     (2,[])
//             (3,[10])                              (3,[9])    
//             (4,[10])                              (4,[9])    
//             (5,[10])
// (6,[10,101])        (6,[10])
// (7,[10,101])  (7,[10,18])  (7,[10])      


// 22 / 54 test cases passed.
// TLE
class Solution {
public:
    int LIShelper(int idx, int lastMax, vector<int> &nums) {
        if(idx >= nums.size())
            return 0;
        
        int pick = INT_MIN;
        if(nums[idx] > lastMax) {
            pick = 1 + LIShelper(idx+1, nums[idx], nums);
        }
        
        int not_pick = LIShelper(idx+1, lastMax, nums);
        
        return max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        return LIShelper(0, INT_MIN, nums);
    }
};




class Solution {
public:
    int LIShelper(vector<int> &nums, int idx, int lastMax, vector<int> &dp) {
        if(idx >= nums.size())
            return 0;
        
        int pick = INT_MIN;
        if(nums[idx] > lastMax) {  
            if(dp[idx] != -1) pick = dp[idx];
            else
                dp[idx] = pick = 1 + LIShelper(nums, idx+1, nums[idx], dp);
        }
        
        int not_pick = LIShelper(nums, idx+1, lastMax, dp);
        
        return max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return LIShelper(nums, 0, INT_MIN, dp);
    }
};


// https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!


class Solution {
public:
    vector<vector<int>> dp;
    int LIShelper(vector<int> &nums, int idx, int lastMaxInd) {
        if(idx >= nums.size())
            return 0;
        
        if(dp[idx][lastMaxInd+1] != -1) return dp[idx][lastMaxInd+1];
        
        int pick = INT_MIN;
        if(lastMaxInd == -1 || nums[idx] > nums[lastMaxInd]) {
            pick = 1 + LIShelper(nums, idx+1, idx);
        }
        
        int not_pick = LIShelper(nums, idx+1, lastMaxInd);
        
        return dp[idx][lastMaxInd+1] = max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), -1));
        return LIShelper(nums, 0, -1);
    }
};


class Solution {
public:
    vector<int> dp;
    int LIShelper(vector<int> &nums, int idx, int lastMaxInd) {
        if(idx >= nums.size())
            return 0;
        
        if(dp[lastMaxInd+1] != -1) return dp[lastMaxInd+1];
        
        int pick = INT_MIN;
        if(lastMaxInd == -1 || nums[idx] > nums[lastMaxInd]) {
            pick = 1 + LIShelper(nums, idx+1, idx);
        }
        
        int not_pick = LIShelper(nums, idx+1, lastMaxInd);
        
        return dp[lastMaxInd+1] = max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums)+1, -1);
        return LIShelper(nums, 0, -1);
    }
};


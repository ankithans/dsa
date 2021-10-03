// recursive
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        
        int oneStep = climbStairs(n-1);
        int twoStep = climbStairs(n-2);
        
        return oneStep + twoStep;
    }
};

// memoization
class Solution {
public:
    vector<int> dp = vector<int>(46, -1);
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        
        if(dp[n] != -1) return dp[n];
        
        int oneStep = climbStairs(n-1);
        int twoStep = climbStairs(n-2);
        
        return dp[n] = oneStep + twoStep;
    }
};

// iterative
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(46, -1);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++) {
            int oneStep = dp[i-1];
            int twoStep = dp[i-2];
            
            dp[i] = oneStep + twoStep;
        }
        return dp[n];
    }
};
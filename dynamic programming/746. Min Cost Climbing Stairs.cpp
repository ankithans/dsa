// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6

// 1->1->1->1->1->1 = 6 cost

// you can start from 0 or 1 index. From that index you can jump 1 or 2 steps.
// Minimize the cost

// write a func which tells what is the min cost from ind to n
// know the ans for n; cost = 0

// recursive TLE
class Solution {
public:
    int minCostHelper(vector<int> &cost, int index) {
        if(index == cost.size()) return 0;
        int minCost = cost[index] + minCostHelper(cost, index+1);
        if(index+2 <= cost.size()) {
            minCost = min(minCost, cost[index] + minCostHelper(cost, index+2));
        }
        return minCost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(minCostHelper(cost, 0), minCostHelper(cost, 1));
    }
};

// iterative
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[cost.size()] == 0;
        for(int i = cost.size()-1; i >= 0; i--) {
            dp[i] = cost[i] + dp[i+1];
            if(i+2 <= cost.size()) {
                dp[i] = min(dp[i], cost[i]+dp[i+2]);
            }
        }
        return min(dp[0], dp[1]);
    }
};
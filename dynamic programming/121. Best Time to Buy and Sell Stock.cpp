// Brute 
// 2 loops; traverse the whole array next to the element we are standing
// O(n^2)

// One pass solution
// O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i] - mini);
        }
        
        return maxi;
    }
};

    
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> maxh;
        for(int n: nums) {
            maxh.push(n);
            if(maxh.size() > k) maxh.pop();
        }
        
        return maxh.top();
    }
};
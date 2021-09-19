class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> maxh;
        for(int i: nums) {
            maxh.push(i);
            if(maxh.size() > 2) maxh.pop();
        }
        
        int x = maxh.top(); maxh.pop();
        int y = maxh.top(); maxh.pop();
        
        return (x-1)*(y-1);
    }
};
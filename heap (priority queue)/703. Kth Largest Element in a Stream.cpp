class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> maxh;
    int k;
    KthLargest(int kk, vector<int>& nums) {
        k = kk;
        for(int n: nums) {
            maxh.push(n);
            if(maxh.size() > k) maxh.pop();
        }
    }
    
    int add(int val) {
        maxh.push(val);
        if(maxh.size() > k) maxh.pop();
        return maxh.top();
    }
};

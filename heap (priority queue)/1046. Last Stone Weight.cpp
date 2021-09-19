class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(int n: stones) maxh.push(n);
        
        while(maxh.size() >= 2) {
            int y = maxh.top(); maxh.pop();
            int x = maxh.top(); maxh.pop();
            
            if(x != y) {
                int newStone = y-x;
                maxh.push(newStone);
            }
        }
        
        return !maxh.empty() ? maxh.top() : 0;
    }
};
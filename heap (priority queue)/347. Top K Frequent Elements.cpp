// brute - sort and count

// heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > maxh;
        vector<int> res;
        
        for(int n: nums) {
            map[n]++;
        }
        
        for(auto it = map.begin(); it != map.end(); it++) {
            maxh.push({it->second, it->first});
            if(maxh.size() > k) maxh.pop();
        }
        
        while(!maxh.empty()) {
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        
        return res;
    }
};
// brute can be sorting
// duplicate and sort it; two for loops
// maintain count if count<3 then gold, silver, bronze; if count>3 then mark it as count; count++;


// heap
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> maxh;
        for(int i = 0; i < score.size(); i++) {
            maxh.push({score[i], i});
        }
        
        int count = 1;
        vector<string> res(score.size());
        while(!maxh.empty()) {
            int ele = maxh.top().first;
            int ind = maxh.top().second;
            maxh.pop();
            
            if(count == 1) res[ind] = "Gold Medal";
            else if(count == 2) res[ind] = "Silver Medal";
            else if(count == 3) res[ind] = "Bronze Medal";
            else res[ind] = to_string(count);
            count++;
        }
        
        return res;
    }
};

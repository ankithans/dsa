// brute way
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        for(int i = 0; i < s.size(); i++) {
            int count = 0;
            unordered_set<int> set;
            for(int j = i; j < s.size(); j++) {
                if(set.find(s[j]) != set.end()) break;
                count++;
                set.insert(s[j]);
            }
            maxi = max(maxi, count);
        }
        
        return maxi;
    }
};


// sliding window 
// !? do a dry run to know hy while not if at map[s[r]] > 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        unordered_map<int, int> map;
    
        int l = 0, r = 0;
        while(r < s.size()) {
            map[s[r]]++;
            
            while(map[s[r]] > 1) {
                map[s[l]]--;
                l++;
            }
            
            maxi = max(maxi, r-l+1);
            r++;
        }
        
        return maxi;
    }
};
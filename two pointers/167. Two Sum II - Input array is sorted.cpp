// brute
// two for loops and find each pair == target or not
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 1; j < nums.size(); j++) {
                if(target == nums[i] + nums[j] && i != j)
                    return {i+1, j+1};
            }
        }
        return {-1,-1};
    }
};

// efficient - 2 pointers
// l = 0; h = n-1; do just like binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;
        
        while(l <= h) {
            if(nums[l] + nums[h] == target)
                return {l+1, h+1};
            else if(nums[l]+nums[h] < target)
                l++;
            else
                h--;
        }
        
        return {-1, -1};
    }
};
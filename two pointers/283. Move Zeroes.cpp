// brute
// create a new array
// push non zero elements first
// then push 0s
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) 
                res.push_back(nums[i]);
        }
        
        for(int i = res.size(); i < n; i++) {
            res.push_back(0);
        }
        
        nums = res;
    }
};

// efficient two pointer with no space
// slow for stopping at 0s
// fast for iterating the array and swapping
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        
        for(int fast = 0; fast < nums.size(); fast++) {
            if(nums[slow] == 0 && nums[fast] != 0)
                swap(nums[slow], nums[fast]);
            
            if(nums[slow] != 0) slow++;
        }
    }
};
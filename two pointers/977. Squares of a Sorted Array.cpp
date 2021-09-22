// brute force
// square the array and sort it
// O(n) + O(nlogn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i]*nums[i];
        }
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// two pointers
// if we abs the negatives, the array is sorted to middle
// so keep l = 0 and h = n-1. and store the square in arr
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        vector<int> res(h+1);
        int k = h;
        
        while(l <= h) {
            if(abs(nums[l]) < abs(nums[h]))
                res[k--] = nums[h]*nums[h--];
            else
                res[k--] = nums[l]*nums[l++];
        }
        
        return res;
    }
};
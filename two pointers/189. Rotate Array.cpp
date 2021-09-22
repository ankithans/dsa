// rotate one and rotate k times
// O(nk) O(1)
class Solution {
public:
    void rightRotateOne(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[n-1];
        
        for(int i=n-1; i>0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }
    void rotate(vector<int>& nums, int k) {
        while(k--) {
            rightRotateOne(nums);
        }
    }
};


// reverse 1st half
// reverse 2nd half
// reverse whole array and you get the ans
// O(n) O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// reverse function can be implemented with two pointers
void reverse(vector<int>& nums, int low, int high) {
    while(low < high) {
        swap(arr[low], arr[high]);
        low++; high--;
    }
}
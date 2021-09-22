// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// O(2^n) + O(2^nlog2^n)
class Solution
{
public:
    void helper(vector<int>& arr, int ind, int sum, vector<int>& res) {
        if(ind == arr.size()) {
            res.push_back(sum);
            return;
        }
        
        // pick
        helper(arr, ind+1, sum+arr[ind], res);
        
        // not pick
        helper(arr, ind+1, sum, res);
    }
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> res;
        helper(arr, 0, 0, res);
        return res;
    }
};
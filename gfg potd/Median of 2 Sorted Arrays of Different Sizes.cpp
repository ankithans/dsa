// https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/

// naive solution
// merge -> sort -> find mid -> find median
class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2) {
        vector<int> merged;
        double median;
        
        for(auto it: array1)
            merged.push_back(it);
        for(auto it: array2)
            merged.push_back(it);
        sort(merged.begin(), merged.end());
        
        int mid = merged.size()/2;
        if(merged.size() % 2 == 0) {
            median = ((double)merged[mid-1] + (double)merged[mid])/2;
        } else {
            median = merged[mid];
        }
        
        return median;
    }
};

// efficient: binary search
// 

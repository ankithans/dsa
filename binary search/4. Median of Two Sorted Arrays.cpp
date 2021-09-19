// brute
// merge sort -> find mid -> find median
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j])
                merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);
        }
        while(i < nums1.size())
            merged.push_back(nums1[i++]);
        while(j < nums2.size())
            merged.push_back(nums2[j++]);

        int mid = merged.size()/2;
        double median = 0;
        if(merged.size() % 2 == 0) {
            median = ((double)merged[mid-1] + (double)merged[mid])/2.0;
        } else {
            median = merged[mid];
        }
        
        return median;
    }
};

// optimized using binary search

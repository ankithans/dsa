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
// divide into two parts
// Input:
// m = 3, n = 4
// array1[] = {1,5,9}
// array2[] = {2,3,6,7}
// [1,2,3,5||,6,7,9] our ans lies in 4 elements

// 1    |   5,9
// 2,3,6|   7
// 1<7 6!<7 low++;

// 1,5  |   9
// 2,3  |   6,7
// 5<6 3<9 correct pair; if n+m is odd then ans=max(l1,l2); else (max(l1,l2)+min(r1,r2))/2.0
class Solution{
    public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n > m) {
            return findMedianSortedArrays(b, a);
        }
        double ans = 0;
        int sn = (n+m+1)/2;
        int low = 0, high = n;
        
        while(low <= high) {
            int mid = (low+high)/2;

            int r1 = mid == 0 ? INT_MIN : a[mid-1];
            int r2 = b[sn-mid-1];
            
            int l1 = mid < n ? a[mid] : INT_MAX;
            int l2 = b[sn-mid];
            
            if(r1 <= l2 && r2 <= l1) {
                if((n+m)%2==1) ans = max(r1, r2);
                else ans = (max(r1, r2)+min(l1,l2))/2.0;
                return ans;
            }
            
            if(r1 > l2) high = mid-1;
            else low = mid+1;
        }
        
        return -1;
    }
};
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
    double MedianOfArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n > m) {
            return MedianOfArrays(b, a);
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
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        return bs(nums,target,l,r);
    }
    int bs(vector<int> v,int x,int l,int r){
        int mid=0;
        if(l<=r){
            mid=(r+l)/2;
        
        if(v[mid]==x){
            return mid;
        }
        if(v[mid]<x){
            return bs(v,x,mid+1,r);
        }
        return bs(v,x,l,mid-1);
        }
        return -1;
    }
};

// Input: nums = [1,2,1]
// Output: [2,-1,2]

// find nge in circular array
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        
        // 1 2 1 => 1 2 1 1 2 1 and calculate nge
        // can use % operator to fake the size
        for(int i = 2*n-1; i >= 0; i--)
        {
            while(!st.empty() && nums[i%n] >= st.top())
                st.pop();
            
            if(!st.empty() && nums[i%n] < st.top())
                nge[i%n] = st.top();
            else
                nge[i%n] = -1;
            
            st.push(nums[i%n]);
        }
        
        return nge;
    }
};
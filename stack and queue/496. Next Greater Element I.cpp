// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]


// brute
for(i = 0 to n-1)
    for(j = i+1 to n-1)
        if(a[j] > a[i])
            nge[i] = a[j];
            break


// iterate from the back
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> map;
        
        // calculate nge for nums2
        for(int i = nums2.size()-1; i >= 0; i--)
        {
            // remove from stack; if num > st.top()
            // below is input in stack; top in the right
            // 2
            // 2 4 => 4 (removing 2 as 2 becomes useless!?)
            // 4 3
            // 4 3 1
            while(!st.empty() && nums2[i] > st.top())
                st.pop();
            
            if(!st.empty() && nums2[i] < st.top())
                map[nums2[i]] = st.top();
            else
                map[nums2[i]] = -1;
            
            st.push(nums2[i]);
        }
        
        // match with nums1
        for(int n: nums1) 
        {
            res.push_back(map[n]);
        }
        
        return res;
    }
};

// iterate from the front
// store the nge - when removing it from stack !?
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> map;
        
        // calculate nge for nums2
        for(int n: nums2)
        {
            while(!st.empty() && n > st.top())
            {
                map[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        // match with nums1
        for(int n: nums1) 
        {
            res.push_back(map.find(n) != map.end() ? map[n] : -1);
        }
        
        return res;
    }
};
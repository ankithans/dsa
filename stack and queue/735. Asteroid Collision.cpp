// Input: aestroids = [-1,3,2,-3]
// Output: [-1]

// -1
// -1

// 3
// -1 3 (left right - so no collison)

// 2
// -1 3 2

// -3 (collision happends when n < 0 && top > 0)
// -1 3 2     -3 ==> -1 3   -3 ==> [-1] 

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> st;
        
        for(int n: a)
        {
            // collision happens when:
            // n < 0 && top > 0 !?
            while(!st.empty() && st.back() > 0 && st.back() < -n)
                st.pop_back();

            // killed all required !?
            if(st.empty() || n > 0 || st.back() < 0)
                st.push_back(n);

            // n == top
            else if(n < 0 && st.back() == -n)
                st.pop_back();
        }
        
        return st;
    }
};
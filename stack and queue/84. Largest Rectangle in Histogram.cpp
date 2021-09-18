// brute
// consider every rectangle and for each rectangle find maximum area they can cover. 
// For each rec, find which other rectangles can be included(on the basis of height)

// select an element; find which is the smaller than that element on left and right side. To check which elements we can take.
// left smaller and right smaller will form my width(r-l)

// two pass solution
// make two arrays leftsmaller and rightsmaller. fill them using nge !?
class Solution {
public:
    vector<int> leftSmaller(vector<int>& heights) {
        vector<int> ls(heights.size());
        stack<int> st;
        
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty())
                ls[i] = 0;
            else
                ls[i] = st.top()+1;
            
            st.push(i);
        }
        return ls;
    }
    
    vector<int> rightSmaller(vector<int>& heights) {
        vector<int> rs(heights.size());
        stack<int> st;
        
        for(int i = heights.size()-1; i>= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty())
                rs[i] = heights.size()-1;
            else
                rs[i] = st.top()-1;
            
            st.push(i);
        }
        return rs;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ls = leftSmaller(heights);
        vector<int> rs = rightSmaller(heights);
        
        int maxArea = 0;
        for(int i = 0 ; i < heights.size(); i++) {
            int w = rs[i]-ls[i]+1;
            int a = heights[i] * w;
            
            maxArea = max(maxArea, a);
        }
        
        return maxArea;
    }
};


// 1 pass solution !? dryrun
// instead of finding for each element, try to find area for guys in stack 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i <= heights.size(); i++) {
            while(!st.empty() && 
                  (i == heights.size() || heights[st.top()] >= heights[i])) { // if i==n means nothing left to compare in right, so compare for elements left
                
                int h = heights[st.top()];
                st.pop();
                
                int w;
                if(st.empty()) w = i;
                else w = i - st.top() - 1;
                
                maxArea = max(maxArea, h*w);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};
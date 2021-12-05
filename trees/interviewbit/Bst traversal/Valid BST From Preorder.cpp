// https://www.interviewbit.com/problems/valid-bst-from-preorder/

// The first node i.e. greater than root will be starting point for right subtree
// All the node from right subtree should be greater than root

// 2 1 0 4 6 7
// |     >>>>2

// 2 1 0 4 6 7
//   |   >>>>1

// 2 1 0 4 6 7
//     | >>>>0

// if this property is true for each ele of arr -> then a valid BST

// Approach 1
// for each node we can find first greater element and then check in the right of greater ele if there is any less ele
// recursively do for every ele in array

// Approach 2
// Find NGE and after it if we find any smaller ele return false

bool validatePreorder(vector<int> &preorder) {
    stack<int> st;
    int root = INT_MIN;
    for(int i = 0; i < preorder.size(); i++) {
        while(!st.empty() && preorder[i] > st.top()) {
            root = st.top();
            st.pop();
        }
        if(preorder[i] < root) return false;
        st.push(preorder[i]);
    }
    return true;
}

class Solution {
public:
    bool match(char a, char b) {
        return (a == '(' && b == ')') ||
               (a == '[' && b == ']') ||
               (a == '{' && b == '}');
    }
    
    bool isValid(string s) {
        stack<char> st;
        
        for(char c: s)
        {
            // push the starting brackets
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                // if direct closing bracket comes then false
                if(st.size() == 0) return false;
                char top = st.top();
                st.pop();
                if(match(top, c))
                    continue;
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};
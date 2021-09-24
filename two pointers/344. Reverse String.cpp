// brute
// create new array and push in it from back
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> rev;
        
        for(int i = s.size()-1; i >= 0; i--) {
            rev.push_back(s[i]);
        }
        s = rev;
    }
};

// optimal 
// two pointers
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, h = s.size()-1;
        
        while(l <= h) {
            swap(s[l++], s[h--]);
        }
    }
};
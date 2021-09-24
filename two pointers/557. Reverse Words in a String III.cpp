// brute force
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string temp = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') temp.push_back(s[i]);
            else {
                reverse(temp.begin(), temp.end());
                vec.push_back(temp);
                temp = "";
            }
        }
        reverse(temp.begin(), temp.end());
        vec.push_back(temp);
        
        s = "";
        for(int i = 0; i < vec.size(); i++) {
            if(i == vec.size()-1)
                s += vec[i];
            else
                s += vec[i] + " ";
        }
        
        return s;
    }
};

// better
// without using extra vector; but string
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string temp = "";
        string res = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') temp.push_back(s[i]);
            else {
                reverse(temp.begin(), temp.end());
                res += temp + " ";
                temp = "";
            }
        }
        reverse(temp.begin(), temp.end());
        res += temp;
        
        return res;
    }
};

// optimal solution
// without extra space
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j+1;
            }
        }
        
        // last string
        reverse(s.begin() + i, s.end());
        return s;
    }
};
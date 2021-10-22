class Solution {
public:
    int mdHelper(string w1, string w2, int i, int j) {
        if(i >= w1.size()) return w2.size() - j;
        if(j >= w2.size()) return w1.size() - i;
        
        int match = INT_MAX, insert = 0, delet = 0, replace = 0, not_match = INT_MAX;
        if(w1[i] == w2[j]) match = mdHelper(w1, w2, i+1, j+1);
        else {
            insert = mdHelper(w1, w2, i, j+1);
            delet = mdHelper(w1, w2, i+1, j);
            replace = mdHelper(w1, w2, i+1, j+1);
            not_match = min({insert, delet, replace}) + 1;
        }
        
        return min(match, not_match);
    }
    int minDistance(string word1, string word2) {
        return mdHelper(word1, word2, 0, 0);
    }
};


class Solution {
public:
    vector<vector<int>> dp;
    int mdHelper(string w1, string w2, int i, int j) {
        if(i >= w1.size()) return w2.size() - j;
        if(j >= w2.size()) return w1.size() - i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int match = INT_MAX, insert = 0, delet = 0, replace = 0, not_match = INT_MAX;
        if(w1[i] == w2[j]) match = mdHelper(w1, w2, i+1, j+1);
        else {
            insert = mdHelper(w1, w2, i, j+1);
            delet = mdHelper(w1, w2, i+1, j);
            replace = mdHelper(w1, w2, i+1, j+1);
            not_match = min({insert, delet, replace}) + 1;
        }
        
        return dp[i][j] = min(match, not_match);
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size()+1, vector<int>(word2.size()+1, -1));
        return mdHelper(word1, word2, 0, 0);
    }
};
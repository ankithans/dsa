

class Solution {
public:
    int lcsHelper(string text1, string text2, int i, int j) {
        if(i == text1.size() || j == text2.size())
            return 0;
        
        if(text1[i] == text2[j])
            return 1 + lcsHelper(text1, text2, i+1, j+1);
        
        return max(lcsHelper(text1, text2, i+1, j), lcsHelper(text1, text2, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return lcsHelper(text1, text2, 0, 0);
    }
};


class Solution {
public:
    vector<vector<int>> dp;
    int lcsHelper(string text1, string text2, int i, int j) {
        if(i == text1.size() || j == text2.size())
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + lcsHelper(text1, text2, i+1, j+1);
        
        return dp[i][j] = max(lcsHelper(text1, text2, i+1, j), lcsHelper(text1, text2, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1, vector<int>(text2.size()+1, -1));
        return lcsHelper(text1, text2, 0, 0);
    }
};

// https://leetcode.com/problems/longest-common-subsequence/discuss/590781/From-Brute-Force-To-DP

class Solution {
public:
    vector<vector<int>> dp;
    int lcsHelper(string text1, string text2, int i, int j) {
        if(i >= text1.size() || j >= text2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int match = 0, not_match = 0;
        if(text1[i] == text2[j]) match = 1 + lcsHelper(text1, text2, i+1, j+1);
        else not_match = max(lcsHelper(text1, text2, i+1, j), lcsHelper(text1, text2, i, j+1));
        
        return dp[i][j] = max(match, not_match);
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1, vector<int>(text2.size()+1, -1));
        return lcsHelper(text1, text2, 0, 0);
    }
};
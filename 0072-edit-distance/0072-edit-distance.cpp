class Solution {
public:
    int recur(int i, int j, string s1, string s2){
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(s1[i] == s2[j]) return recur(i-1, j-1, s1, s2);

        int ins = 1 + recur(i, j-1, s1, s2);
        int repl = 1 + recur(i-1, j-1, s1, s2);
        int del = 1 + recur(i-1, j, s1, s2);

        return min(ins, min(repl, del));
    }
    int memo(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = memo(i-1, j-1, s1, s2, dp);

        int ins = 1 + memo(i, j-1, s1, s2, dp);
        int repl = 1 + memo(i-1, j-1, s1, s2, dp);
        int del = 1 + memo(i-1, j, s1, s2, dp);

        return dp[i][j] = min(ins, min(repl, del));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // return recur(n-1, m-1, word1, word2);

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return memo(n-1, m-1, word1, word2, dp);
    }
};
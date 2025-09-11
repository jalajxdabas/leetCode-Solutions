class Solution {
public: 
    bool solve(int i, int j, string s1, string s2, string s3){
        int x = s1.size();
        int y = s2.size();

        if(i == x && j == y) return true;

        int k = i+j;

        bool ans = false;

        if(s1[i] == s3[k]) ans |= solve(i+1, j, s1, s2, s3);
        if(s2[j] == s3[k]) ans |= solve(i, j+1, s1, s2, s3);

        return ans;
    }

    bool memo(int i, int j, string s1, string s2, string s3, vector<vector<int>> &dp){
        int x = s1.size();
        int y = s2.size();

        if(i == x && j == y) return true;

        if(dp[i][j] != -1) return dp[i][j];

        int k = i+j;

        bool ans = false;

        if(s1[i] == s3[k]) ans |= memo(i+1, j, s1, s2, s3, dp);
        if(s2[j] == s3[k]) ans |= memo(i, j+1, s1, s2, s3, dp);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();

        if(x+y != z) return false;

        vector<vector<int>> dp(x+1, vector<int>(y+1, -1));

        // return solve(0, 0, s1, s2, s3);
        return memo(0, 0, s1, s2, s3, dp);
    }
};
class Solution {
public:
    int recur(int i, int j, string s, string t){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(s[i] == t[j]) {
            return (recur(i-1, j-1, s, t) + recur(i-1, j, s, t));
        }
        else{
            return recur(i-1, j, s, t);
        }
    }
    int memo(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = (memo(i-1, j-1, s, t, dp) + memo(i-1, j, s, t, dp));
        }
        else{
            return dp[i][j] = memo(i-1, j, s, t, dp);
        }
    }

    int tab(string s, string t){
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];

    }

    int space(string s, string t){
        int n = s.size();
        int m = t.size();

        vector<double> prev(m+1, 0);
        vector<double> curr(m+1, 0);
        prev[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) curr[j] = prev[j-1] + prev[j];
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[m];
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return recur(n-1, m-1, s, t);
        // return memo(n-1, m-1, s, t, dp);

        return tab(s, t);
    }
};
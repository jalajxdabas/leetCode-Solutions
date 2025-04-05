class Solution {
public:
    bool recur(int i, int j, string s, string p){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0) {
            for(int x = 0; x<=i; x++){
                if(s[x] != '*') return false;
            }
            return true;
        }

        if(s[i] == p[j] || s[i] == '?') return recur(i-1, j-1, s, p);
        if(s[i] == '*') return (recur(i-1, j, s, p) || recur(i, j-1, s, p));
        return false;
    }

    bool memo(int i, int j, string s, string p, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0) {
            for(int x = 0; x<=i; x++){
                if(s[x] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || s[i] == '?') return dp[i][j] = memo(i-1, j-1, s, p, dp);
        if(s[i] == '*') return dp[i][j] = (memo(i-1, j, s, p, dp) || memo(i, j-1, s, p, dp));
        return dp[i][j] = false;
    }

    bool tab(int m, int n, string p, string s){
        vector<vector<bool>> dp(m+1, vector<bool> (n+1));

        dp[0][0] = true;
        for(int j=1; j<=n; j++) dp[0][j] = false;

        for(int i=1; i<=m; i++){
            int f1 = true;
            for(int x=1; x<=i; x++){
                if(p[x-1] != '*'){
                    f1 = false;
                    break;
                }
            }
            dp[i][0] = f1;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[m][n];

    }

    bool isMatch(string s, string p) {
       int n = s.size();
       int m = p.size();

    //    return recur(m-1, n-1, p, s);
    // vector<vector<int>> dp(m, vector<int> (n, -1));
    // return memo(m-1, n-1, p, s, dp);
    return tab(m, n, p, s);
    }
};
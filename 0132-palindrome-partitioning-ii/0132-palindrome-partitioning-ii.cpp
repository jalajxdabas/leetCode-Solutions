class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int recur(int i, string s){
        int n = s.length();
        if(i == n) return 0;

        int mini = 1e8;
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + recur(j+1, s);
                mini = min(mini, cost);
            }
        }
        return mini;
    }
    int memo(int i, string s, vector<int> &dp){
        int n = s.length();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = 1e8;
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + memo(j+1, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    int tab(string s){
        int n = s.length();
        vector<int> dp(n+1, 0);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            int mini = 1e8;
            for(int j=i; j<n; j++){
                if(isPal[i][j]){
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
    int minCut(string s) {
        int n = s.length();

        // return recur(0, s) - 1;
        // vector<int> dp(n, -1);
        // return memo(0, s, dp) -1;

        return tab(s);
    }
};
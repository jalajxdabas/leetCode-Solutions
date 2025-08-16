class Solution {
public:
    int recur(int n){
        if(n == 0 || n == 1) return 1;

        return (recur(n-1) + recur(n-2));
    }

    int memo(int n, vector<int> &dp){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = (memo(n-1, dp) + memo(n-2, dp));
    }

    int tab(int n){
        vector<int> dp(n+1, 0);

        dp[0] = dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int space(int n){
        int prev1 = 1;
        int prev2 = 1;
        int curr;

        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }


    int climbStairs(int n) {
        // return recur(n);

        // vector<int> dp(n+1, -1);
        // return memo(n, dp);

        // return tab(n);

        return space(n);
    }
};
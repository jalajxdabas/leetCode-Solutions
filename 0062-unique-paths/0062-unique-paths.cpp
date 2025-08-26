class Solution {
public:
    int recur(int i, int j){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        int up = recur(i-1, j);
        int down = recur(i, j-1);
        return up+down;
    }

    int memo(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return dp[i][j] = 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = memo(i-1, j, dp);
        int down = memo(i, j-1, dp);
        return dp[i][j] = up+down;
    }


    int tab(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                
                int down = 0;
                int right = 0;

                if(i>0) down = dp[i-1][j];
                if(j>0) right = dp[i][j-1];

                dp[i][j] = down+right;
            }
        }
        return dp[m-1][n-1];
    }



    int uniquePaths(int m, int n) {
        
        // return recur(m-1, n-1);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memo(m-1, n-1, dp);

        return tab(m, n);
    }
};
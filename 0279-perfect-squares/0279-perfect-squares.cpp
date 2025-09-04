class Solution {
public:
    int solve(int idx, vector<int> &squares, int n) {
        if(n == 0) return 0;
        if(idx < 0 || n < 0) return 1e9;

        int take = 1 + solve(idx, squares, n - squares[idx]);
        int notTake = solve(idx - 1, squares, n);

        return min(take, notTake);
    }

    int memo(int idx, vector<int> &squares, int n, vector<vector<int>> &dp){
        if(n == 0) return 0;
        if(idx < 0 || n < 0) return 1e9;

        if(dp[idx][n] != -1) return dp[idx][n];

        int take = 1 + memo(idx, squares, n - squares[idx], dp);
        int notTake = memo(idx - 1, squares, n, dp);

        return dp[idx][n] = min(take, notTake);
    }

    int numSquares(int n) {
        int sqr = sqrt(n);
        vector<int> squares;
        for(int i = 1; i <= sqr; i++) {
            squares.push_back(i * i);
        }
        // return solve(sqr - 1, squares, n);

        vector<vector<int>> dp(sqr, vector<int>(n+1, -1));
        return memo(sqr-1, squares, n, dp);
    }
};

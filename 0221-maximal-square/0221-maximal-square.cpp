class Solution {
public:
    int solve(int row, int col, vector<vector<char>> matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        if(row >= m || col >= n || matrix[row][col] == '0') return 0;

        int right = solve(row, col+1, matrix);
        int diag = solve(row+1, col+1, matrix);
        int down = solve(row+1, col, matrix);

        return 1 + min(right, min(diag, down));
    }

    int memo(int row, int col, vector<vector<char>> &matrix, vector<vector<int>> &dp){
        int m = matrix.size();
        int n = matrix[0].size();

        if(row >= m || col >= n || matrix[row][col] == '0') return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int right = memo(row, col+1, matrix, dp);
        int diag = memo(row+1, col+1, matrix, dp);
        int down = memo(row+1, col, matrix, dp);

        return dp[row][col] = 1 + min(right, min(diag, down));
    }


    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    // ans = max(ans, solve(i, j, matrix));
                    ans = max(ans, memo(i, j, matrix, dp));

                }
            }
        }

        return ans*ans;
    }
};
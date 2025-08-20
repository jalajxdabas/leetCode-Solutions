class Solution {
public:

    int recur(int i, int j, vector<vector<int>> &matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        if(i >= m || j >= n) return 0;

        if(matrix[i][j] == 0) return 0;

        int right = recur(i, j+1, matrix);
        int down = recur(i+1, j, matrix);
        int diag = recur(i+1, j+1, matrix);

        return (1+ min(right, min(down, diag)));
    }

    int memo(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        int m = matrix.size();
        int n = matrix[0].size();

        if(i >= m || j >= n) return 0;

        if(matrix[i][j] == 0) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = memo(i, j+1, matrix, dp);
        int down = memo(i+1, j, matrix, dp);
        int diag = memo(i+1, j+1, matrix, dp);

        return dp[i][j] = (1+ min(right, min(down, diag)));
    }



    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));


        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if (matrix[i][j] == 1){
        //             // result += recur(i, j, matrix);
        //             result += memo(i, j, matrix, dp);
        //         } 
        //     }
        // }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(i == 0 || j == 0) dp[i][j] = matrix[i][j];

                else if(matrix[i][j] == 0) dp[i][j] = 0;

                else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));

                result += dp[i][j];
            }
        }

        return result;
    }
};
class Solution {
public:
    int recur(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int m = matrix.size();
        int n = matrix[0].size();
        int best = 1;

        if(dp[row][col] != -1) return dp[row][col];

        for(int i=0; i<4; i++){
            int x = row + dx[i];
            int y = col + dy[i];

            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[row][col]){
                
                best = max(1+recur(x, y, matrix, dp), best);
            }
        } 
        return dp[row][col] = best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                
                ans = max(ans, recur(i, j, matrix, dp));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int dfs(int row, int col, vector<vector<int>> &grid){
        grid[row][col] = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int m = grid.size();
        int n = grid[0].size();

        int best = 1;

        for(int i=0; i<4; i++){
            int x = row + dx[i];
            int y = col + dy[i];        
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                best += dfs(x, y, grid);
            }

        }
        return best;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();

        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count = 1;
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};
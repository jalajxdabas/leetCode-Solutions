class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int x = row + dx[i];
            int y = col + dy[i];

            if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == '1'){
                dfs(x, y, grid, vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;


    }
};
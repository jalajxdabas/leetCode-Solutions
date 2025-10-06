class Solution {
public:
    void dfs(int row, int col, int &ans, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<4; i++){
            int x = row + dx[i];
            int y = col + dy[i];

            if(x >= 0 && x<m && y >= 0 && y < n){
                if(grid[x][y] == 0) ans++;
                else if(!vis[x][y]) dfs(x, y, ans, grid, vis);
                else continue;
            }
            else{
                ans++;
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(i, j, ans, grid, vis);
                }
            }
        }
        return ans;
    }
};
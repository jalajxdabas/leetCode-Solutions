class Solution {
public:
    void solve(int row, int col, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        // up
        for(int i = row - 1; i >= 0; i--){
            if(grid[i][col] == 2 || grid[i][col] == 1) break; // wall or guard
            grid[i][col] = 3; // guarded
        }

        // down
        for(int i = row + 1; i < m; i++){
            if(grid[i][col] == 2 || grid[i][col] == 1) break;
            grid[i][col] = 3;
        }

        // left
        for(int j = col - 1; j >= 0; j--){
            if(grid[row][j] == 2 || grid[row][j] == 1) break;
            grid[row][j] = 3;
        }

        // right
        for(int j = col + 1; j < n; j++){
            if(grid[row][j] == 2 || grid[row][j] == 1) break;
            grid[row][j] = 3;
        }
        
        return;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(auto i: guards){
            int r = i[0];
            int c = i[1];

            grid[r][c] = 1;
        }
        for(auto i: walls){
            int r = i[0];
            int c = i[1];

            grid[r][c] = 2;
        }


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    solve(i, j, grid);
                }
            }
        }
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    // cout<<i<<j<<endl;
                    count++;
                }
            }
        }
        return count;

        
    }
};
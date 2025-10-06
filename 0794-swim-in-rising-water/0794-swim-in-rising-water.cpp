class Solution {
public:


    bool isPossible(int row, int col, int t, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col] = true;
        int n = grid.size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        if(row == n-1 && col == n-1) return true;

        for(int i=0; i<4; i++){
            int x = row + dx[i];
            int y = col + dy[i];

            if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && grid[x][y] <= t){
                if(isPossible(x, y, t, grid, vis)) return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0;
        int right = n * n - 1;
        int ans = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            if (grid[0][0] > mid) {
                left = mid + 1;
                continue;
            }
            if(isPossible(0, 0, mid, grid, vis)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};
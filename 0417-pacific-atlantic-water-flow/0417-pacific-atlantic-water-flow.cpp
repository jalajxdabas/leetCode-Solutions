class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &heights){
        if(vis[row][col] == 1) return;
        int m = heights.size();
        int n = heights[0].size();

        vis[row][col] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int newx = row + dx[i];
            int newy = col + dy[i];

            if(newx >= 0 && newx < m && newy >= 0 && newy < n && vis[newx][newy] == 0 && heights[newx][newy] >= heights[row][col]){
                dfs(newx, newy, vis, heights);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            dfs(0, i, pac, heights);
            dfs(m-1, i, atl, heights);
        }
        
        for(int i=0; i<m; i++){
            dfs(i, 0, pac, heights);
            dfs(i, n-1, atl, heights);
        }


        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] == 1 && atl[i][j] == 1) ans.push_back({i, j});
            }
        }

        return ans;


        
    }
};
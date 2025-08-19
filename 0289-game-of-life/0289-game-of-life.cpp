class Solution {
public:
    void solve(int row, int col, vector<vector<int>> &vis){
        int m = vis.size();
        int n = vis[0].size();

        int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dy[] = {0, +1, +1, +1, 0, -1, -1, -1};

        for(int i=0; i<=7; i++){
            int newx = row + dx[i];
            int newy = col + dy[i];

            if(newx >= 0 && newx < m && newy >= 0 && newy < n ){
                vis[newx][newy]++;
            }
        }
        return;


    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1) solve(i, j, vis);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (vis[i][j] == 3) board[i][j] = 1 ;
                
                else if(board[i][j] == 1){
                    if(vis[i][j] < 2) board[i][j] = 0;
                    else if(vis[i][j] > 3) board[i][j] = 0;
                }

            }
        }
        return;

    }
};
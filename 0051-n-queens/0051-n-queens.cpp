class Solution {
public:
    void solve(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            vector<string> temp;
            for(int i=0; i<n; i++){
                string row = "";
                for(int j=0; j<n; j++){
                    row += board[i][j];
                }
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }
        
        

        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
            else{
                board[row][col] = '.';
            }
        }

    }

    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        int x = row;
        int y = col;

        while(y >= 0){
            if(board[row][y--] == 'Q' ) return false;
        }

        y = col;

        while(x >= 0 && y >= 0){
            if(board[x--][y--] == 'Q') return false;
        }

        x = row;
        y = col;

        while(x < n && y >=0){
            if(board[x++][y--] == 'Q') return false;
        }
        return true;

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};
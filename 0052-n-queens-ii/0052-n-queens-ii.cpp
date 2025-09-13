class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){

        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j]) return false;
        }

        for(int i=col; i>=0; i--){
            if(board[row][i]) return false;
        }

        for(int i=row, j=col; i<n && j>=0; i++,j--){
            if(board[i][j]) return false;
        }
        return true;
    }
    void solve(int col, vector<vector<int>> &board, int n, int &count){
        if(col == n) {
            count+=1;
            return;
        }

        for(int row = 0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                solve(col+1, board, n, count);
                board[row][col] = 0;
            }
            else continue;
        }
        
    }

    
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<int>> board(n+1, vector<int>(n+1, 0));
        solve(0, board, n, count);
        return count;

    }
};
class Solution {
public:
    bool isSafe(int row, int col, char val, vector<vector<char>> &board){
        int count = 0;
        for(int i=0; i<9; i++){
            if(board[row][i] == val) count++;
            if(board[i][col] == val) count++;

            if(board[3*(row/3) + (i/3)][3*(col/3) + i%3] == val) count++;

            if(count > 3) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        int n = board.size();

        for(int i=0; i<9; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != '.'){
                    if(isSafe(i, j, board[i][j], board));
                    else return false;
                }
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = false;
        ans = solve(board);
        return ans;
    }
};
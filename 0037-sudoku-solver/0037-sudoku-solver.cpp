class Solution {
public:
    bool solve(vector<vector<char>> &board, int n){
        for(int row=0; row<9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char ch = '1'; ch<='9'; ch++){
                        if(isSafe(row, col, ch, board)){
                            board[row][col] = ch;
                            bool nextSolution = solve(board, n);

                            if(nextSolution) return true;
                            else {
                                board[row][col] = '.';
                            }

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isSafe(int row, int col, char val, vector<vector<char>> &board){
        for(int i=0; i<9; i++){
            if(board[i][col] == val) return false;

            if(board[row][i] == val) return false;

            if(board[3*(row/3)+i/3][3*(col/3) + i%3] == val){
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board, n);
        return;
    }
};
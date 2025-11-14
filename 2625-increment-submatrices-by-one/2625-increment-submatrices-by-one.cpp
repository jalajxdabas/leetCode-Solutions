class Solution {
public:
    void solve(vector<vector<int>> &grid, int r1, int c1, int r2, int c2){

        for(int r = r1; r <= r2; r++) {
            for(int c = c1; c <= c2; c++) {
                grid[r][c]++;
            }
    }
        return;
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n, 0));

        for(auto i: queries){
            solve(grid, i[0], i[1], i[2], i[3]);
        }

        return grid;
    }
};
class Solution {
public:
    void sortDiag(int row, int col, vector<vector<int>> &grid, bool asc){
        int i = row;
        int j = col;
        int n = grid.size();

        vector<int> temp;

        while(i < n && j < n){
            temp.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc) sort(temp.begin(), temp.end());
        else sort(temp.rbegin(), temp.rend());


        i = row;
        j = col;
        int idx = 0;

        while(i < n && j < n){
            grid[i][j] = temp[idx];
            i++;
            j++;
            idx++;
        }

        return;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int row = 0; row<n; row++){
            sortDiag(row, 0, grid, false);
        }

        for(int col = 1; col <n; col++){
            sortDiag(0, col, grid, true);
        }

        return grid;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = m-1;

        while(row < m && col >= 0){
            int ele = matrix[row][col];

            if(ele == target) return true;
            
            if(ele < target){
                row++;
            }
            else col--;
        }

        return false;
    }
};
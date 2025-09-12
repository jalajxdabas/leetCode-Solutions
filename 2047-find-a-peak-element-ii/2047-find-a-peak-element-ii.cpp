class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int top = 0, bottom = m - 1;

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;

            int maxCol = 0;
            for (int j = 1; j < n; j++) {
                if (mat[mid][j] > mat[mid][maxCol]) {
                    maxCol = j;
                }
            }

            int up = (mid > 0) ? mat[mid - 1][maxCol] : -1;
            int down = (mid < m - 1) ? mat[mid + 1][maxCol] : -1;

            if (mat[mid][maxCol] > up && mat[mid][maxCol] > down) {
                return {mid, maxCol};
            } else if (down > mat[mid][maxCol]) {
                top = mid + 1;
            } else {
                bottom = mid - 1;
            }
        }

        return {-1, -1};
    }
};

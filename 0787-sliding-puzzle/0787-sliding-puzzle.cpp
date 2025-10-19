class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};

        queue<pair<vector<vector<int>>, int>> q;
        q.push({board, 0});
       map<vector<vector<int>>, int> vis;
        vis[board] = 1;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = INT_MAX;

        while(!q.empty()){
            auto curr = q.front().first;
            auto steps = q.front().second;

            q.pop();

            if(curr == target){
                ans = min(ans, steps);
            }

            int row, col;
            for(int i=0;i<2; i++){
                for(int j=0; j<3; j++){
                    if(curr[i][j] == 0) {
                        row = i;
                        col = j;
                        break;

                    }
                }
            }

            for(int i=0; i<4; i++){
                int newx = row + dx[i];
                int newy = col + dy[i];

                if(newx >= 0 && newx < 2 && newy >= 0 && newy < 3){
                    swap(curr[newx][newy], curr[row][col]);
                    if(vis.find(curr) == vis.end()){
                        q.push({curr, steps+1});
                        vis[curr]++;
                    }
                    swap(curr[newx][newy], curr[row][col]);
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
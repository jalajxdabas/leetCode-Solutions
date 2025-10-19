class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] ==1 ){
                    q.push({0, {i, j}});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int dist = top.first;
            int x = top.second.first;
            int y = top.second.second;

            for(int i=0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < m && newy >= 0 && newy < n && !vis[newx][newy]){
                    ans[newx][newy] = dist+1;
                    vis[newx][newy] = 1;
                    q.push({dist+1, {newx, newy}});
                }
            }
        }
        return ans;


    }
};
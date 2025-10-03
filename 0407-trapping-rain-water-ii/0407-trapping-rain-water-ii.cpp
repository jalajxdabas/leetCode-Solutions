class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<P, vector<P>, greater<>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            pq.push({heightMap[i][0], {i, 0}});
            vis[i][0] = true;
            pq.push({heightMap[i][n-1], {i, n-1}});
            vis[i][n-1] = true;
        }

        for(int j=0; j<n; j++){
            pq.push({heightMap[0][j], {0, j}});
            vis[0][j] = true;
            pq.push({heightMap[m-1][j], {m-1, j}});
            vis[m-1][j] = true;
        }
        int total = 0;
        while(!pq.empty()){
            P P = pq.top();
            pq.pop();

            int h = P.first;
            int i = P.second.first;
            int j = P.second.second;

            for(auto x: dir){
                int newi = i + x[0];
                int newj = j + x[1];

                if(newi >= 0 && newi < m && newj >= 0 && newj < n && !vis[newi][newj]){
                    total += max(h - heightMap[newi][newj], 0);
                    pq.push({max(h, heightMap[newi][newj]), {newi, newj}});
                    vis[newi][newj] = true;
                }
            }
        }
        return total;

    }
};
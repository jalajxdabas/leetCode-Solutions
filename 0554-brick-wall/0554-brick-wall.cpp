class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();

        unordered_map<int, int> mp;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(wall[i].empty()) continue;
            long long sum = 0;
            for(int j = 0; j<wall[i].size() - 1; j++){
                sum += wall[i][j];
                mp[sum]++;
                ans = max(ans, mp[sum]);
            }
        }
        return (n-ans);
    }
};
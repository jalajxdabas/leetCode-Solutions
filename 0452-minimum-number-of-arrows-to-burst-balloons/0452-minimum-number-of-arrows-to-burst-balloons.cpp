class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        int curr = -1;
        int ans = 0;
        for(auto i: points){
            int start = i[0];
            int end = i[1];

            if(curr == -1 || curr < start) {
                
                curr = end;
                ans++;
            } else {
                    
                curr = min(curr, end);
            }
        }
        return ans;
    }
};

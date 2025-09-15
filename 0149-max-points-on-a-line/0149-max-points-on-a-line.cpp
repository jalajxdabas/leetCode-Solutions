class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            unordered_map<string, int> slope;
            int count = 1;
            int maxi = INT_MIN;

            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x1 == x2 && y1 == y2) {
                    count++;
                    continue;
                }

                int x = x2 - x1;
                int y = y2 - y1;

                int gcd = __gcd(x, y);
                x /= gcd;
                y /= gcd;

                if(x < 0 && y < 0 || x > 0 && y < 0){
                    x *= -1;
                    y *= -1;
                }

                string key = to_string(x) + "-" + to_string(y);
                slope[key]++;
                maxi = max(maxi, slope[key]);

            }
            ans = max(ans, maxi+count);

        }
        return ans;
    }
};
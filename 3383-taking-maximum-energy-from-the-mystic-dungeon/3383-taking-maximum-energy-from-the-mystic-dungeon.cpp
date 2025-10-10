class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int maxi = INT_MIN;

        for(int i=n-1; i>=(n-k); i--){
            dp[i] = energy[i];
            maxi = max(maxi, dp[i]);
        }

        for(int i=n-k-1; i>=0; i--){
            dp[i] = dp[i+k] + energy[i];
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
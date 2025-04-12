class Solution {
public:
    int recur(int i, int k, vector<int> &arr){
        int n = arr.size();
        if(i == n) return 0;

        int len = 0;
        int ans = -1e8;
        int maxi = 0;

        for(int j=i; j< min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (maxi*len) + recur(j+1, k, arr);
            ans = max(sum, ans);
        }
        return ans;
    }

    int memo(int i, int k, vector<int> &arr, vector<int> &dp){
        int n = arr.size();
        if(i == n) return 0;
        if(dp[i]!=-1) return dp[i];

        int len = 0;
        int ans = -1e8;
        int maxi = 0;

        for(int j=i; j< min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (maxi*len) + memo(j+1, k, arr, dp);
            ans = max(sum, ans);
        }
        return dp[i] = ans;
    }

    int tab(int n, int k, vector<int> &arr){
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int len = 0;
            int ans = -1e8;
            int maxi = 0;

            for(int j=i; j< min(n, i+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (maxi*len) + dp[j+1];
                ans = max(sum, ans);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // return recur(0, k, arr);

        // vector<int> dp(n, -1);
        // return memo(0, k, arr, dp);

        return tab(n, k, arr);
    }
};
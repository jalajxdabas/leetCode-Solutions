class Solution {
public:
    int recur(int i, int prev, vector<int>& nums){
        if(i == nums.size()) return 0;

        int notTake = 0 + recur(i+1, prev, nums);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) take = 1 + recur(i+1, i, nums);
        return max(take, notTake);
    }

    int memo(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int notTake = 0 + memo(i+1, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) take = 1 + memo(i+1, i, nums, dp);
        return dp[i][prev+1] = max(take, notTake);
    }

    int tab(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n, 0));

        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                int notTake = 0 + dp[i+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[i] > nums[prev]) take = 1 + dp[i+1][i+1];
                dp[i][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return recur(0, -1, nums);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return memo(0, -1, nums, dp);
    }
};
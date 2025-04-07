class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) totalSum += nums[i];

        if(totalSum%2 != 0) return false;

        int target = totalSum/2;

        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int k=1; k<=target; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(k >= nums[i]) take = dp[i-1][k-nums[i]];

                dp[i][k] = take||notTake;
            }
        }
        return dp[n-1][target];

    }
};
class Solution {
public:
    int recur(int i, int j, vector<int> &nums){
        if(i > j) return 0;
        
        int maxi = -1;
        for(int ind=i; ind<=j; ind++){
            int cost = (nums[i-1] * nums[ind] * nums[j+1]) + recur(i, ind-1, nums) + recur(ind+1, j, nums);
            maxi = max(cost, maxi);
        }
        return maxi;
    }

    int memo(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = -1;
        for(int ind=i; ind<=j; ind++){
            int cost = (nums[i-1] * nums[ind] * nums[j+1]) + memo(i, ind-1, nums, dp) + memo(ind+1, j, nums, dp);
            maxi = max(cost, maxi);
        }
        return dp[i][j] = maxi;
    }

    int tab(int n, vector<int> &nums){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=i; j<=n; j++){
                
                for(int ind=i; ind<=j; ind++){
                    int cost = (nums[i-1] * nums[ind] * nums[j+1]) + dp[i][ind-1] + dp[ind+1][j];
                    dp[i][j] = max(cost, dp[i][j]);
                }
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        // return recur(1, n, nums);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return memo(1, n, nums, dp);

        return tab(n, nums);
    }
};
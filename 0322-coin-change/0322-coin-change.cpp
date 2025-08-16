class Solution {
public:
    int recur(int i, vector<int>& coins, int amount){
        if(i == 0) {
            if(amount % coins[i] == 0) return amount/coins[i];
            else return 1e9;
        }

        if(amount == 0) return 1;

        int take = 1e9;
        int notTake = recur(i-1, coins, amount);
        if(amount >= coins[i]) take = 1 + recur(i, coins, amount-coins[i]);

        return min(take, notTake);
    }

    int memo(int i, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(i == 0) {
            if(amount % coins[i] == 0) return dp[i][amount] = amount/coins[i];
            else return dp[i][amount] = 1e9;
        }

        if(amount == 0) return dp[i][amount] = 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 1e9;
        int notTake = memo(i-1, coins, amount, dp);
        if(amount >= coins[i]) take = 1 + memo(i, coins, amount-coins[i], dp);

        return dp[i][amount] = min(take, notTake);
    }

    int tab(vector<int> coins, int amount){
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i = 0; i<= amount; i++){
            if(i % coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        dp[0][0] = 0;

        for(int i=1; i<n; i++){
            for(int target = 0; target <= amount; target++){
                int notTake = dp[i-1][target];
                int take = 1e9;
                if(target >= coins[i]) take = 1 + dp[i][target-coins[i]];

                dp[i][target] = min(take, notTake);
            }
        }

        return (dp[n-1][amount] == 1e9)? -1 : dp[n-1][amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = recur(n-1, coins, amount);


        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = memo(n-1, coins, amount, dp);
        // return (ans == 1e9? -1 : ans);

        return tab(coins, amount);
    }
};
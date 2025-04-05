class Solution {
public:
    int recur(int i, bool buy, vector<int> prices){
        if(i == prices.size()) return 0;
        int profit = 0;

        if(buy){
            profit = max((-prices[i] + recur(i+1, 0, prices)), recur(i+1, 1, prices)); 
        }
        else{
            profit = max(recur(i+1, 0, prices), (+prices[i] + recur(i+1, 1, prices)));
        }
        return profit;
    }

    int memo(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;
        int profit = 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            profit = max((-prices[i] + memo(i+1, 0, prices, dp)), memo(i+1, 1, prices, dp)); 
        }
        else{
            profit = max(memo(i+1, 0, prices, dp), (+prices[i] + memo(i+1, 1, prices, dp)));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // return recur(0, buy, prices);
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return memo(0, 1, prices, dp);
    }

};
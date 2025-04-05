class Solution {
public: 
    int recur(int i, bool buy, int cap, vector<int> &prices){
        if(cap == 0) return 0;
        if(i == prices.size()) return 0;

        int profit = 0;
        if(buy){
            profit = max(recur(i+1, 1, cap, prices), (-prices[i] + recur(i+1, 0, cap, prices)));
        }
        else{
            profit = max(recur(i+1, 0, cap, prices), (+prices[i]+recur(i+1, 1, cap-1, prices)));
        }
        return profit;
    }

    int memo(int i, bool buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(i == prices.size()) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;
        if(buy){
            profit = max(memo(i+1, 1, cap, prices, dp), (-prices[i] + memo(i+1, 0, cap, prices, dp)));
        }
        else{
            profit = max(memo(i+1, 0, cap, prices, dp), (+prices[i]+memo(i+1, 1, cap-1, prices, dp)));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // return recur(0, 1, 2, prices);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memo(0, 1, 2, prices, dp);
    }
};
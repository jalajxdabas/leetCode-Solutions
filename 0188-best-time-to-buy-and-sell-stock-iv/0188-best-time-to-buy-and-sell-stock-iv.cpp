class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<=k; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(next[1][cap], (-prices[i] + next[0][cap]));
                    }
                    else{
                        profit = max(next[0][cap], (+prices[i]+next[1][cap-1]));
                    }
                    curr[buy][cap] = profit;
                }
                next = curr;
            }
        }
        return next[1][k];
    }
};
class Solution {
public:
    int recur(int i, int j, vector<int> &cuts){
        if(i > j) return 0;
        int mini = 1e9;

        for(int ind = i; ind<=j; ind++){
            int cost = (cuts[j+1]-cuts[i-1]) + recur(i, ind-1, cuts) + recur(ind+1, j, cuts);
            mini = min(cost, mini);
        }
        return mini;
    }
    
    int memo(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        for(int ind = i; ind<=j; ind++){
            int cost = (cuts[j+1]-cuts[i-1]) + memo(i, ind-1, cuts, dp) + memo(ind+1, j, cuts, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }

    int tab(vector<int> &cuts, int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i > j) continue;
                int mini = 1e9;
                for(int ind = i; ind<=j; ind++){
                    int cost = (cuts[j+1]-cuts[i-1]) + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n];
        
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        // vector<vector<int>> dp(c+1, vector<int>(c+1, -1));

        // return recur(1, c, cuts);
        // return memo(1, c, cuts, dp);

        return tab(cuts, c);
    }
};
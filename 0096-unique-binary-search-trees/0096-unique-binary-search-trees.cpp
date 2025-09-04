class Solution {
public:
    int solveTab(int n){
        vector<int> dp(n+1, 0); 
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){ // number of nodes

            for(int j = 1; j<=i; j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }

    int numTrees(int n) {
        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);

        return solveTab(n);
       
    }
};
class Solution {
public:
    void solve(int idx, vector<int> temp, vector<vector<int>> &ans, int k, int n){
        if(k == 0 && n == 0){
            ans.push_back(temp);
            return;
        }

        if(n < 0 || k <= 0 || idx == 10) return;

        temp.push_back(idx);
        solve(idx+1, temp, ans, k-1, n-idx);
        temp.pop_back();
        solve(idx + 1, temp, ans, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, temp, ans, k, n);

        return ans;
    }
};
class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> &path, int target, int i, int sum){
        if(sum == target){
            ans.push_back(path);
            return;
        }

        if(sum > target || i >= nums.size()) return;

        path.push_back(nums[i]);
        solve(nums, ans, path, target, i, sum+nums[i]);
        path.pop_back();
        solve(nums, ans, path, target, i+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        long sum = 0;

        solve(nums, ans, path, target, 0, sum);
        return ans;
    }
};
class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> &path, int target, int i, int sum){
        if(sum == target){
            ans.push_back(path);
            return;
        }

        if(sum > target || i >= nums.size()) return;

        for(int idx = i; idx<nums.size(); idx++){
            path.push_back(nums[idx]);
            solve(nums, ans, path, target, idx, sum+nums[idx]);
            path.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        long sum = 0;

        solve(nums, ans, path, target, 0, sum);
        return ans;
    }
};
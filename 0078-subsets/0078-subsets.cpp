class Solution {
public:
    void solve(int i, vector<int> nums, vector<int> output, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(output);
            return;
        }

        solve(i+1, nums, output, ans);
        output.push_back(nums[i]);
        solve(i+1, nums, output, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(0, nums, output, ans);
        return ans;

    }
};
class Solution {
public:
    void solve(int idx, vector<int> &nums,  vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        int n = nums.size();

        for(int i =idx; i<n; i++){
            swap(nums[i], nums[idx]);
            solve(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        solve(0, nums, ans);
        return ans;
    }
};
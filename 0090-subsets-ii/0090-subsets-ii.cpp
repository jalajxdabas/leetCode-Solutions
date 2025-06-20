class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int index, vector<int> &path){
        ans.push_back(path);
        int n = nums.size();

        for(int i=index; i < n ; i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            solve(nums, ans, i+1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());

        solve(nums, ans, 0, path);
        return ans;
    }
};
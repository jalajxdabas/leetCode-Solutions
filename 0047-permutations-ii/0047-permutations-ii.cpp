class Solution {
public:
    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        set<int> st;
        for(int i=idx; i<nums.size(); i++){
            if(st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            solve(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        solve(0, nums, ans);
        return ans;
    }
};
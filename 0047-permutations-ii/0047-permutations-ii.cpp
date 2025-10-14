class Solution {
public:
    void solve(int idx, vector<int> &nums, set<vector<int>> &temp){
        if(idx == nums.size()){
            if(temp.find(nums) == temp.end()){
                temp.insert(nums);
            }
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            // if(i > 0 && nums[i] == nums[i-1]) continue;
            swap(nums[i], nums[idx]);
            solve(idx+1, nums, temp);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> temp;

        solve(0, nums, temp);

        for(auto i: temp){
            ans.push_back(i);
        }
        return ans;
    }
};
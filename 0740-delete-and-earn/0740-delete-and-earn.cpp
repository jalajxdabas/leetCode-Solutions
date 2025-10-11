class Solution {
public:
    int recur(int i, vector<int> &nums, unordered_map<int, int> &mp){
        if(i == nums.size()) return 0;
        

        int notTake = recur(i+1, nums, mp);
        int take = INT_MIN;
        if(i == 0 || nums[i] != nums[i-1]){
            take = nums[i] * mp[nums[i]];
            int j = i;
            while(j < nums.size() && nums[j] <= nums[i]+1) j++;
            take += recur(j, nums, mp);
        }

        return max(take, notTake);
    }

    int memo(int i, vector<int> &nums, unordered_map<int, int> &mp, vector<int> &dp){
        if(i == nums.size()) return 0;
        if(dp[i] !=-1) return dp[i];

        int notTake = memo(i+1, nums, mp, dp);
        int take = INT_MIN;
        if(i == 0 || nums[i] != nums[i-1]){
            take = nums[i] * mp[nums[i]];
            int j = i;
            while(j < nums.size() && nums[j] <= nums[i]+1) j++;
            take += memo(j, nums, mp, dp);
        }

        return dp[i] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        unordered_map<int, int> mp;

        for(auto i: nums) mp[i]++;

        // return recur(0, nums, mp);
        vector<int> dp(n, -1);
        return memo(0, nums, mp, dp);
    }
};
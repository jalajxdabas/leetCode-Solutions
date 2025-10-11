class Solution {
public:
    long long recur(int i, vector<int> &nums, unordered_map<int, int> &mp){
        if(i == nums.size()) return 0;
        

        long long notTake = recur(i+1, nums, mp);
        long long take = INT_MIN;
        if(i == 0 || nums[i] != nums[i-1]){
            take = nums[i] * mp[nums[i]];
            int j = i;
            while(j < nums.size() && nums[j] <= nums[i]+1) j++;
            take += recur(j, nums, mp);
        }

        return max(take, notTake);
    }

    long long memo(int i, vector<int> &nums, unordered_map<int, int> &mp, vector<long long> &dp){
        if(i == nums.size()) return 0;
        if(dp[i] !=-1) return dp[i];

        long long notTake = memo(i+1, nums, mp, dp);
        long long take = INT_MIN;
        if(i == 0 || nums[i] != nums[i-1]){
            take = 1LL * nums[i] * mp[nums[i]];
            int j = i;
            while(j < nums.size() && nums[j] <= nums[i]+2) j++;
            take += memo(j, nums, mp, dp);
        }

        return dp[i] = max(take, notTake);
    }
    long long maximumTotalDamage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> dp(n, -1);

        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;

        return memo(0, nums, mp, dp);
    }
};
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int maxi = -1e9;
        int mini = 1e9;
        int ans = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);

            if(maxi - mini <= k) continue;
            else {
                ans++;
                i--;
                maxi = -1e9;
                mini = 1e9;
            }
        }
        return ans;
    }
};
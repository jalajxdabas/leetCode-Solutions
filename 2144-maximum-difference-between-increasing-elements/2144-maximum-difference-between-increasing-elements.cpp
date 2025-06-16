class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int ans = -1;

        for(int i=0; i<n; i++){
            mini = min(mini, nums[i]);

            if(nums[i] > mini) ans = max(ans, (nums[i]-mini));
        }
        return ans;
    }
};
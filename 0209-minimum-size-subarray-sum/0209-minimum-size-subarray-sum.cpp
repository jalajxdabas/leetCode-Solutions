class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9;
        int sum = 0;
        int l = 0;
        int r = 0;

        int n = nums.size();

        while(r < n){
            sum += nums[r];

            while(sum >= target){
                ans = min(ans, r-l+1);
                sum -= nums[l++];
            }
            r++;
        }
        if(ans == 1e9) return 0;
        return ans;
    }
};
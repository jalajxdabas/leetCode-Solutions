class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }

        int count = 0;
        int ans = 0;

        for(int &i: nums){
            if(i == maxi) {
                ans = max(ans, ++count);
            }
            else count = 0;
        }
        return ans;
    }
};
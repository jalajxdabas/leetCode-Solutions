class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int curr = 1;
        int prev = 0;   
        int ans = 1;

        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }

            if(curr > 2*ans){
                ans = curr/2;
            }

            if(min(prev, curr) > ans) ans = min(prev, curr);
        }
        return ans;
    }
};
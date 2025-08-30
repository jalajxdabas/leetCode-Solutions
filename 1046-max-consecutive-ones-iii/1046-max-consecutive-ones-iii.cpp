class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int ans = INT_MIN;

        int left = 0;
        int right = 0;

        while(right < nums.size()){
            if(nums[right] == 0){
                count++;
                while(count > k){
                    if(nums[left] == 0) count--;
                    left++;
                }
            }
            ans = max(ans, (right-left+1));
            right++;
        }
        return ans;
    }
};
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int start = 0;
        int end = 0;
        int window = 0;
        int n = nums.size();

        while(end < n){
            if(nums[end] >= left && nums[end] <= right) window = end-start + 1;
            else if(nums[end] < left) window = window;
            else {
                window = 0;
                start = end+1;
            }
            end++;
            ans += window;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n-1;
        int x = n-1;

        while(left <= right){
            if(abs(nums[left]) < abs(nums[right])){
                ans[x] = nums[right] * nums[right];
                right--;
                x--;
            }
            else{
                ans[x] = nums[left] * nums[left];
                left++;
                x--;
            }
        }
        return ans;
    }
};
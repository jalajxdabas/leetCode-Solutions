class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for(int i=0; i<n; i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0){
                ans = idx+1;
                break;
            }
            nums[idx] *= -1;
        }
        return ans;
    }
};
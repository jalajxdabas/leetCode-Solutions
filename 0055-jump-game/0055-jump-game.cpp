class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        for(int i=0; i<n-1; i++){

            maxi = max(maxi, nums[i] + i);
            if(maxi<=i) return false;
        }
        return true;
    }
};
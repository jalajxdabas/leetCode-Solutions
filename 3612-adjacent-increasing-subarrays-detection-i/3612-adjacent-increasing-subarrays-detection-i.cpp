class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int curr = 1;
        int prev = 0;
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }

            if(curr >= 2*k) return true;

            if(min(curr, prev) >= k) return true;
        }
        return false;
    }
};
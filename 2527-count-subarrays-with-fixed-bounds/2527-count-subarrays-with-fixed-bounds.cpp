class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        
        int mini = -1;
        int maxi = -1;
        int cult = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK) cult = i;

            if(nums[i] == minK) mini = i;
            if(nums[i] == maxK) maxi = i;

            long long smaller = min(mini, maxi);
            long long temp = smaller - cult;

            ans += (temp <= 0)? 0: temp;
        }
        return ans;

    }
};
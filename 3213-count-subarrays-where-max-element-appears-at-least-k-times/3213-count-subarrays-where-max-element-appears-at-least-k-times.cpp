class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(begin(nums), end(nums));

        int n = nums.size();
        long long ans = 0;

        int i=0; 
        int j=0;
        int count = 0;
        while(j < n){
            if(nums[j] == maxi){
                count++;
            }

            while(count >= k){
                ans += (n-j);

                if(nums[i] == maxi) count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
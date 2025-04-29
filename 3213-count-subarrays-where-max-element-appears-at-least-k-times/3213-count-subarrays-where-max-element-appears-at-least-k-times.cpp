class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(begin(nums), end(nums));

        int n = nums.size();
        long long ans = 0;

        vector<int> maxIndex;

        for(int i=0; i<n; i++){
            if(maxi == nums[i]){
                maxIndex.push_back(i);
            }
            int size = maxIndex.size();
            if(size >= k){
                int last_i = maxIndex[size-k];
                ans += (last_i + 1);
            }
        }
        return ans;
    }
};
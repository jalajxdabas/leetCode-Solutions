class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = -1;
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            sum += nums[i];
            r = i;

            if(mp[nums[i]] > 1){
                while(l <= r && mp[nums[i]] > 1){
                    sum -= nums[l];
                    mp[nums[l]]--;
                    l++;
                }
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
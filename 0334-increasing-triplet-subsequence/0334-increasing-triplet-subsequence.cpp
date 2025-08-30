class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = min(prefix[i-1], nums[i]);
        }

        suffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = max(nums[i], suffix[i+1]);
        }


        for(int i=0; i<n; i++){
            if(prefix[i] != nums[i] && nums[i] != suffix[i]) return true;
        }
        return false;
    }
};
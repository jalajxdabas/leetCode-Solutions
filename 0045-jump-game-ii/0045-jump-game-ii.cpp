class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n);

        maxi[0] = nums[0];

        for(int i=1; i<n; i++){
            maxi[i] = max(nums[i] + i, maxi[i-1]);
        }

        int ans = 0;
        int idx = 0;

        while(idx < n-1){
            ans++;
            idx = maxi[idx];
        }
        return ans;

    }
};
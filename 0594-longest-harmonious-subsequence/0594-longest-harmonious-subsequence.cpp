class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();

        while(l < n && r < n){
            int d = nums[r] - nums[l];

            if(d == 1) {ans = max(ans, (r-l+1));
                r++;
            }
            else if(d == 0) r++;
            else l++;
        }
    return ans;
        
    }
};
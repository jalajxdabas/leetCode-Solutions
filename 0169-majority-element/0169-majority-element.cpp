class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int ans = nums[0];
        int n = nums.size();

        for(int i=1; i<n; i++){
            int curr = nums[i];
            if(count == 0) ans = nums[i];

            if(curr == ans) count++;
            else{
                count --;
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long sum = 0;
        long long count = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(sum == sum + nums[i]){
                count++;
                ans += count;
            }
            else{
                count = 0;
                sum += nums[i];
            }
        }
        return ans;
    }
};
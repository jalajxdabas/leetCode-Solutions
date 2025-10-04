class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if(n < 3) return nums[n-1];
        int count = 0;
        for(int i=n-1; i>=0; i--){
            count++;
            while(i > 0 && nums[i-1] == nums[i]) i--;
            if(count == 3) return nums[i];
        }
        return nums[n-1];
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        int count = 1;
        int parity = 0;

        for(int num: nums){
            if(num%2 == 0) even++;
            else odd++;
        }

        parity = nums[0] % 2;

        for(int i=1; i<nums.size(); i++){
            int curr = nums[i]%2;

            if(curr != parity){
                count++;
                parity = curr;
            }
            else continue;
        }

        return max(odd, max(even, count));
    }
};
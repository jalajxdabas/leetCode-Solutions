class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        int count = 0;

        bool flag = nums[0] % 2 == 1; // odd at start

        for(int num: nums){
            if(num % 2 == 1){
                if(flag){
                    flag = !flag;
                    count++;
                }
                odd++;
            }
            else{
                if(!flag){
                    flag = !flag;
                    count++;
                }
                even++;
            }
        }

        return max(odd, max(even, count));
    }
};
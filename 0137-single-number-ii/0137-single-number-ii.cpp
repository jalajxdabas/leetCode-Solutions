class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int bit = 0; bit<32; bit++){
            int temp = (1<<bit);
            int one = 0;
            int zero = 0;

            for(int &num: nums){
                if((temp & num) == 0) zero++;
                else one++;
            }

            if((one%3) == 1){
                result = (result | temp);
            }
        }
        return result;
    }
};
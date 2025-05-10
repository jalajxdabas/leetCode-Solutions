class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        long long zero1 = 0;
        long long zero2 = 0;

        for(int &i: nums1){
            sum1 += i;
            if(i == 0){
                sum1 += 1;
                zero1++;
            }
        }

        for(int &i: nums2){
            sum2 += i;
            if(i == 0){
                sum2 += 1;
                zero2++;
            }
        }

        if(sum1 < sum2 && zero1 == 0) return -1;
        else if(sum2 < sum1 && zero2 == 0) return -1;
        else return max(sum1, sum2);
    }
};
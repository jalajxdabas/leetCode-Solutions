class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int count = 0;

        for(int i: nums) sum += i;

        int n = nums.size();
        for(int i: nums){
            int right = sum - left-i;

            if(i == 0){
                if(left == right) count+=2;
                else if(left == right-1 || right == left - 1){
                    count++;
                }
            }
            left += i;
        }
        return count;
    }
};
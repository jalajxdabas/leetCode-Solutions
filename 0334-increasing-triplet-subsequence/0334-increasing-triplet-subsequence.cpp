class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        int n = nums.size();

        for(int num: nums){
            
            if(num <= first) first = num;
            else if(num <= second) second = num;
            else return true;

        }

        return false;
    }
};
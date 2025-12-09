class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;

        for(int i: nums){
            right[i]++;
        }
        int result = 0;
        int M = 1e9+7;

        int n = nums.size();

        for(int i: nums){
            right[i]--;

            int l = left[2*i];
            int r = right[2*i];

            result = (result + (1LL * l*r)%M)%M;

            left[i]++;
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n/3; i++){
            int first = nums[3*i];
            int second = nums[3*i + 1];
            int third = nums[3*i + 2];

            if(third - second <= k && third - first <= k && second - first <= k){
                ans.push_back({first, second, third});
            }
            else{
                return {};
            }
        }
        return ans;
    }
};
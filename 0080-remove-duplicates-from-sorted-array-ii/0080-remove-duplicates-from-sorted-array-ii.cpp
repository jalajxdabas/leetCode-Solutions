class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        int k = 1;
        for(int i=2; i<n; i++){
            if(nums[i] != nums[k] || nums[i] != nums[k-1]){
                nums[++k] = nums[i];
            }
            else continue;
        }
        return k+1;
    }
};
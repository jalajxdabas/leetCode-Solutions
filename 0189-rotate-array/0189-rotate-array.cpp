class Solution {
public:
    void reverse(vector<int> &nums, int s, int e){
        for(int i=0; i<(e-s)/2; i++){
            swap(nums[i+s], nums[e-i-1]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
    }
};
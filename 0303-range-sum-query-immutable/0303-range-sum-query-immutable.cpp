class NumArray {
public:
    vector<long long> prefix;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i: nums){
            prefix.push_back(sum);
            sum += i;
            
        }
        prefix.push_back(sum);
    }
    
    int sumRange(int left, int right) {
        return (prefix[right+1] - prefix[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
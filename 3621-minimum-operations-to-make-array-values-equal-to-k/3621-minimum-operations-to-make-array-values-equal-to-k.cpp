class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0] < k) return -1;
        else if(nums[0] == k){
            int count = 0;
            int temp = k;
            for(int i=1; i<n; i++){
                if(nums[i] == temp) continue;
                else{
                    temp = nums[i];
                    count++;
                }
            }
            return count;
        }
        else{
            int count = 0;
            int temp = nums[0];
            for(int i=1; i<n; i++){
                if(nums[i] == temp) continue;
                else{
                    temp = nums[i];
                    count++;
                }
            }
            return count+1;
        }

        
    }
};
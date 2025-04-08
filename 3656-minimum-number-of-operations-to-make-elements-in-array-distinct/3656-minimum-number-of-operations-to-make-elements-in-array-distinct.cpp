class Solution {
public:
    bool isDistinct(unordered_map<int, int> &temp){
        for(auto& [u, v] : temp){
            if(v > 1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> temp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            temp[nums[i]]++;
        }
        
        if(isDistinct(temp)) return 0;

        int k = 0;
        while(!nums.empty()){
            if(nums.size() < 3) return k+1;

            for(int i=0; i<3; i++){
                temp[nums[i]]--;
                if(temp[nums[i]] == 0) temp.erase(nums[i]);
            }
            nums.erase(nums.begin(), nums.begin()+3);
            k++;
            if(isDistinct(temp)) return k;
        }
        return k;
    }
};
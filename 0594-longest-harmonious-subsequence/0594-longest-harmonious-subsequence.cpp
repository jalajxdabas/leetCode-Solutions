class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int &num: nums){
            mp[num]++;
        }

        int ans = 0;

        for(int &num: nums){
            int mini = num;
            int maxi = num+1;

            if(mp[maxi] > 0){
                ans = max(ans, mp[mini]+mp[maxi]);
            }
        }
        return ans;

    }
};
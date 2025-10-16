class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;

        for(auto i: nums){
            int r = ((i%value) + value) %value;
            mp[r]++;
        }

        int ans = 0;

        while(mp[(ans % value)] > 0){
            mp[(ans % value)]--;
            ans++;
        }
        return ans;
    }
};
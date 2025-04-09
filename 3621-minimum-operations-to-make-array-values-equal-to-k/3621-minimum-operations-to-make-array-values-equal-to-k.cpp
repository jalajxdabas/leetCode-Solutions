class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int mini = 1e9;
        for(auto i: nums){
            mp[i] = 1;
            mini = min(mini, i);
        }
        if(mini < k) return -1;
        int ans = mp.size();
        if(mp[k]) ans--;
        return ans;

    }
};
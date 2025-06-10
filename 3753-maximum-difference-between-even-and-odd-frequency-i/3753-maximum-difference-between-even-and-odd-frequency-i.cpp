class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        for(auto &it : s){
            mp[it]++;
        }

        int odd = 0;
        int even = 1e9;
        for(auto &it: mp){
            if(it.second % 2 != 0) odd = max(odd, it.second);
            else even = min(even, it.second);
        }

        return (odd-even);
    }
};
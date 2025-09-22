class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        int count = 0;

        for(int i: nums){
            mp[i]++;
            if(maxi <= mp[i]){
                maxi = mp[i];
                
            }
        }

        for(auto i: mp){
            if(i.second == maxi) count += i.second;
        }
        return count;
    }
};
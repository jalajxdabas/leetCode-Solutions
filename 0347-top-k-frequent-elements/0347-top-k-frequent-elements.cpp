class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int &i: nums){
            mp[i]++;
        }

         auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> maxi(comp);

        for(auto &i: mp){
            maxi.push({i.first, i.second});
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(maxi.top().first);
            maxi.pop();
        }
        return ans;
    }
};
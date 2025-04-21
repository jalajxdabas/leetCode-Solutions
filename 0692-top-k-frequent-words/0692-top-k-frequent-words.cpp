class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;
        for(auto &s: words){
            mp[s]++;
        }

        vector<pair<string, int>> freq_vec(mp.begin(), mp.end());
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;  // Lexicographical order if frequencies are the same
            }
            return a.second > b.second;  // Higher frequency comes first
        });

        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freq_vec[i].first);
        }

        return result;
        
    }
};
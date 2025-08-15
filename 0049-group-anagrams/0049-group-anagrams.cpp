class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto &i: strs){
            string key = i;
            sort(i.begin(), i.end());
            mp[i].push_back(key);
        }

        for(auto &i: mp){
            ans.push_back(i.second);
        }
        return ans;


    }
};
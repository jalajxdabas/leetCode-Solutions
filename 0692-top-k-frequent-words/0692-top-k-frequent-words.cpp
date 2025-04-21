class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        sort(words.begin(), words.end());

        unordered_map<string, int> mp;
        vector<string> ans;

        for(string &s: words){
            mp[s]++;
        }

        auto comp = [](pair<string, int> &a, pair<string, int> &b){
            if(a.second != b.second){
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> maxi(comp);

        for(auto &i: mp){
            maxi.push({i.first, i.second});
        }

        for(int i=0; i<k; i++){
            pair<string, int> it = maxi.top();
            maxi.pop();

            ans.push_back(it.first);
        }



        return ans;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char &ch: s){
            mp[ch]++;
        }

        auto comp = [](pair<char, int> &a, pair<char, int> &b){
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> maxi(comp);

        for(auto &i: mp){
            maxi.push({i.first, i.second});
        }

        string ans = "";
        while(!maxi.empty()){
            pair<char, int> p = maxi.top();
            maxi.pop();
            ans.append(p.second, p.first);
        }
        return ans;
    }
};
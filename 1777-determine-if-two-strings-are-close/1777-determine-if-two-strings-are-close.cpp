class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for( auto ch: word1) mp1[ch]++;
        for(auto ch: word2) mp2[ch]++;

        unordered_set<char> s1, s2;
        for(auto &p: mp1) s1.insert(p.first);
        for(auto &p: mp2) s2.insert(p.first);

        if(s1 != s2) return false;

        vector<int> freq1;
        vector<int> freq2;

        for(auto &i: mp1) freq1.push_back(i.second);
        for(auto &i: mp2) freq2.push_back(i.second);

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return (freq1 == freq2);
    }
};
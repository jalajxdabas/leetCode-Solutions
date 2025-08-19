class Solution {
public:
    bool wordPattern(string s, string pattern) {
        vector<string>v;
        stringstream ss(pattern);
        string word;
        while(ss >> word) {
            v.push_back(word);
        }

        if(s.length() != v.size()) return false;
        
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;


        for(int i=0; i<v.size(); i++) {
            if((mp1.find(s[i]) != mp1.end() && mp1[s[i]] != v[i]) || (mp2.find(v[i]) != mp2.end() && mp2[v[i]] != s[i])) return false;
            if(mp1.find(s[i]) == mp1.end()) mp1[s[i]] = v[i];
            if(mp2.find(v[i]) == mp2.end()) mp2[v[i]] = s[i];
        }

        return true;
    }
};
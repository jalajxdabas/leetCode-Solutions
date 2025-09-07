class Solution {
public:
    bool match(string s, string p){
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        
        int n = s.length();

        for(int i=0; i<n; i++){
            char c1 = s[i], c2 = p[i];

            if(mp1.find(c1) != mp1.end()){
                if(mp1[c1] != c2 ) return false;
            }
            else mp1[c1] = c2;

            if(mp2.find(c2) != mp2.end()){
                if(mp2[c2] != c1 ) return false;
            }
            else mp2[c2] = c1;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;

        for(auto s: words){
            if(match(s, p)) ans.push_back(s);
        }
        return ans;
    }
};
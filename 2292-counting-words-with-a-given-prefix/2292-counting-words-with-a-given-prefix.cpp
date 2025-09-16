class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size();
        int count = 0;

        for(auto s: words){
            if(s.size() < n) continue;

            if(s.substr(0, n) == pref) count++;
        }
        return count;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorSum = 0;
        for(int i = 0; i<s.size(); i++){
             xorSum = xorSum ^ s[i];
        }
        for(int i = 0; i<t.size(); i++){
            xorSum = xorSum ^ t[i];
        }
        return char(xorSum);
    }
};
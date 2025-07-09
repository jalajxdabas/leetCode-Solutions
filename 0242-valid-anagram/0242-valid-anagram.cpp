#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        int count[26] = {0};

        for (size_t i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};
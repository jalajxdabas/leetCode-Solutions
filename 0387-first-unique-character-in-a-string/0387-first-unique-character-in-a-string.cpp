class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            count[s[i]]++;
        }
        int i = 0;
        while (i < n) {
            for (auto it : count) {
                if (s[i] == it.first && it.second == 1) {
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};
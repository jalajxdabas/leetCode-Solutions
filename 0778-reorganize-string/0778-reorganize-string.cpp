class Solution {
public:
    string reorganizeString(string s) {
        int maxi = 0;
        int maxf = 0;
        int n = s.length();
        vector<int> freq(26, 0);
        for(auto ch: s) {
            if (++freq[ch-'a'] > maxf){
                maxf = freq[ch-'a'];
                maxi = ch-'a';
            }
        }

        if (2 * maxf - 1 > n) return "";
        int i = 0;
        while(freq[maxi]--){
            s[i] = 'a' + maxi;
            i += 2;
        }
        for (int j = 0; j < 26; ++j) {
            while (freq[j]-- > 0) {
                if (i >= n) i = 1;
                s[i] = 'a' + j;
                i += 2;
            }
        }
        return s;
    }
};
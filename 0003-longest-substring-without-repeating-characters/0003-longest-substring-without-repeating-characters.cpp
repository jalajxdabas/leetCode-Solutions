class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 1;
        if(n == 0) return 0;

        for(int i=0; i<n-1; i++){
            unordered_map<char, int> mp;
            mp[s[i]]++;
            for(int j=i+1; j<n; j++){
                char ch = s[j];
                if(mp[ch] > 0) break;
                else{
                    mp[ch]++;
                    ans = max(ans, (j-i+1));
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        unordered_map<char, int> mp = {{'a', 0}, {'b', 0}, {'c', 0}};
        
        int n = s.length();

        int left = 0;
        int right = 0;

        while(right < n){
            mp[s[right]]++;

            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                ans += (n-right);
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;

    }
};
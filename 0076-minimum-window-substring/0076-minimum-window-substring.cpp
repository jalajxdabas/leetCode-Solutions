class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.length();
        int p_len = t.length();

        if(s_len < p_len) return "";

        unordered_map<char, int> mp;

        for(char &ch: t){
            mp[ch]++;
        }

        int i=0, j=0;
        int start_i = 0;
        int ans = INT_MAX;
        int count = p_len;

        while(j < s_len){
            char ch = s[j];

            if(mp[ch] > 0){
                count--;
            }

            mp[ch]--;

            while(count == 0){

                int curr = j-i+1;
                if(curr < ans){
                    ans = curr;
                    start_i = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0) count++;
                i++;
            }
            j++;
        }

        if(ans == INT_MAX) return "";
        else return s.substr(start_i, ans);


    }
};
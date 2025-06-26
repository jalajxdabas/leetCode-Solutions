class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();

        if(s_len < p_len) return {};

        vector<int> ans;
        vector<int> freq(26, 0);
        vector<int> count(26, 0);

        for(int i=0; i<p_len; i++){
            freq[p[i] - 'a']++;
            count[s[i]-'a']++;
        }

        if(freq == count) ans.push_back(0);

        int l = 0;
        int r = p_len-1;

        while(r < s_len-1){
            
            count[s[l++] - 'a']--;
            count[s[++r] - 'a']++;

            if(freq == count) ans.push_back(l);
        }
        return ans;

        

    }
};
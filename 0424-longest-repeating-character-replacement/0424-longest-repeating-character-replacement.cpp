class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> freq(26, 0);
       int left = 0, right = 0, maxi = INT_MIN, ans=0;

       while(right < s.length()){
            freq[s[right] - 'A']++;
            
            maxi = max(maxi, freq[s[right] - 'A']);

            while((right - left + 1) - maxi > k){
                freq[s[left] - 'A']--;
                left++;
                maxi = 0;
                for(int i=0; i<26; i++){
                    maxi = max(maxi, freq[i]);
                }
            }

            if((right - left + 1) - maxi <= k){
                ans = max(ans, (right - left + 1));
            }
            right++;
       }
       return ans;




    }
};
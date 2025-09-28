class Solution {
public:
    string solve(string s, int left, int right){
        
        int n = s.length();

        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();

        for(int i=0; i<n; i++){
            string odd = solve(s, i, i);
            string even = solve(s, i, i+1);

            if(odd.length() > ans.length()) ans = odd;
            if(even.length() > ans.length()) ans = even;
        }

        return ans;
        

    }
};
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            ans += solve(s, i, i);
            ans += solve(s, i, i+1);
        }
        return ans;
    }

    int solve(string s, int left, int right){
        int count = 0;
        while(left >=0 && right<s.length() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }

};
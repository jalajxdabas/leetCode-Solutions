class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.length();

        for(int i=0; i<n; i++){
            char ch = s[i];
            int count = 1;
            while(i < n-1 && s[i+1] == ch){
                count++;
                i++;
            }

            count = (count < 3 ? count : 2);

            while(count){
                ans += ch;
                count--;
            }
        }
        return ans;
    }
};
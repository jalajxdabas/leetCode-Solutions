class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        int idx = 0;

        for(int i=0; i<n; i++){
            if(idx < 2 || s[idx-1] != s[idx-2] || s[idx-1] != s[i]){
                s[idx++] = s[i];
            }
        }
        return s.substr(0, idx);
    }
};
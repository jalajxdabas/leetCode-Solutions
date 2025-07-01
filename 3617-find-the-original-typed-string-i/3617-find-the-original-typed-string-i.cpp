class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;

        int n = word.length();

        for(int i=0; i<n-1; i++){
            char ch = word[i];
            while(ch == word[i+1]){
                i++;
                ans++;
            }
        }
        return ans;
    }
};
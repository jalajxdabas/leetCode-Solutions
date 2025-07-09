class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        string ans = "";
        bool match = true;

        for(int i=0; i<strs[0].length(); i++){
            char ch = strs[0][i];

            for(int j=1; j<n; j++){
                if(i > strs[j].size() || strs[j][i] != ch){
                    match = false;
                    break;
                }
            }

            if(match == false){
                return ans;
            }
            else if(match){
                ans += ch;
            }
        }
        return ans;
    }
};
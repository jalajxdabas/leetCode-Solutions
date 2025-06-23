class Solution {
public:
    void solve(string digits, string output, int idx, vector<string> &ans, string mapping[]){
        if(idx >= digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[idx] - '0';
        string value = mapping[num];

        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, idx+1, ans, mapping);
            output.pop_back();
        }
        return;

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;

        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};    
        solve(digits, output, 0, ans, mapping);
        return ans;
    }
};
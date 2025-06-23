class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        solve(s, 0, path, ans);
        return ans;
    }

    void solve(string s, int index, vector<string> &path, vector<vector<string>> &ans){
        int n = s.length();
        if(index == n) {
            ans.push_back(path);
            return;
        }

        for(int i=index; i<n; i++){
            if(isPalindrome(index, i, s)){
                path.push_back(s.substr(index, i-index+1));
                solve(s, i+1, path, ans);
                path.pop_back();
            }
        }


    }

    bool isPalindrome(int l, int r, string s){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};
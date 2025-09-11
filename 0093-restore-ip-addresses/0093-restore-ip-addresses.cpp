class Solution {
public:
    void solve(int idx, string temp, string s, vector<string> &ans, int dots){
        if(dots == 3){
            if(valid(s.substr(idx))){
                ans.push_back(temp + s.substr(idx));
            }
            return;
        }

        int n = s.size();

        for(int i=idx; i<min(idx+3, n); i++){
            if(valid(s.substr(idx, i-idx+1))){
                temp.push_back(s[i]);
                temp.push_back('.');
                solve(i+1, temp, s, ans, dots+1);
                temp.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp = "";

        solve(0, temp,s, ans, 0);
        return ans;

    }
    bool valid(string temp){
        if(temp.size()>3 || temp.size()==0) return false; // segment length should be between 1 and 3
        if(temp.size()>1 && temp[0]=='0')   return false; // segment should not start with 0, unless it is a single digit
        if(temp.size() && stoi(temp)>255) return false; // segment should not be greater than 255
        return true;
    }
};
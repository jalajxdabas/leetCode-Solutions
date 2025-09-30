class Solution {
public:
    unordered_set<string> st;

    int t[301];

    bool solve(int i, string s){
        if(i >= s.length()) return t[i] = true;
        int n = s.length();

        if(st.find(s) != st.end()) return t[i] = true;

        if(t[i] != -1) return t[i];


        for(int j = 1; j<= n-i; j++){
            string temp = s.substr(i, j);

            if(st.find(temp) != st.end() && solve(i+j, s)) return t[i] = true;
        }
        return t[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &i: wordDict){
            st.insert(i);
        }

        memset(t, -1, sizeof(t));

        return solve(0, s);
    }
};
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastOcc; 
        int n = s.length();

        for(int i=0; i<n; i++){
            lastOcc[s[i]] = i;
        }

        stack<char> st;
        unordered_set<char> vis;

        for(int i=0; i<n; i++){
            if(vis.find(s[i]) != vis.end()) continue;

            while(!st.empty() && s[i] < st.top() && i <lastOcc[st.top()]){
                vis.erase(st.top());
                st.pop();
            }

            vis.insert(s[i]);
            st.push(s[i]);
        }

        string ans = "";

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
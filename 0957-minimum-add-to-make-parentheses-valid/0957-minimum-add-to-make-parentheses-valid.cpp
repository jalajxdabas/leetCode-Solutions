class Solution {
public:
    int minAddToMakeValid(string s) {
      stack<char> st;
      int n = s.length();
      int ans = 0;

      for(int i=0; i<n; i++){
        if(s[i] == '(') st.push(s[i]);
        else{
            if(!st.empty() && st.top() == '(') st.pop();
            else ans++;
        }
      }  

        return ans + st.size();
    }
};
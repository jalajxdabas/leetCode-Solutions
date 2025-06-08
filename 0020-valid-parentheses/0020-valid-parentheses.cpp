
class Solution {
public:
    bool isValid(string s) {

        if (s.length() == 0) {
            return false;
        }

        if(s.length()%2!=0) return false;

        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            if((ch == '(') || (ch == '{') || (ch == '[')){
                st.push(ch);
            }
            else{
                if(st.size()!=0){
                    char top = st.top();
                    
                    if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }

                }
                else{
                    return false;
                }
                
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
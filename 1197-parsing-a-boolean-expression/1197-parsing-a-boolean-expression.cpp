class Solution {
public:
    char solve(vector<char> &val, char op){
        if(op == '!') return val[0] == 't'? 'f':'t';
        else if(op == '&'){
            for(int i=0; i<val.size(); i++){
                if(val[i] == 'f') return 'f';
            }
            return 't';
        }
        else{
            for(int i=0; i<val.size(); i++){
                if(val[i] == 't') return 't';
            }
            return 'f';
        }
    }
    bool parseBoolExpr(string exp) {
        int n = exp.length();

        stack<char> st;

        for(int i=0; i<n; i++){
            if(exp[i] == ',') continue;

            else if(exp[i] == ')' ){
                vector<char> val;
                while(st.top() != '('){
                    val.push_back(st.top());
                    st.pop();
                }st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(val, op));
            }
            else{
                st.push(exp[i]);
            }
        }
        return st.top() == 't'? true : false;
    }
};
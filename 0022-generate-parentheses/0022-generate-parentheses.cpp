class Solution {
public:
    void solve(int open, int close, string op, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }


        if(open == close){
            string temp = op;
            temp.push_back('(');
            solve(open-1, close, temp, ans);
        }
        else if(open == 0){
            string temp = op;
            temp.push_back(')');
            solve(open, close-1, temp, ans);
        }
        else if(close == 0){
            string temp = op;
            temp.push_back('(');
            solve(open-1, close, temp, ans);
        }
        else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(open-1, close, op1, ans);
            solve(open, close-1, op2, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op;

        solve(open, close, op, ans);
        return ans;
    }
};
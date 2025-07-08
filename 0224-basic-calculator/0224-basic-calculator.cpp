class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int ans = 0;
        int f = 1;
        int i = 0;

        while(i < n){
            if(s[i] == ' ') i++;
            
            if(s[i] >= '0' && s[i] <= '9'){
                string temp = "";
                while(i < n && s[i] >='0' && s[i] <= '9'){
                    if(s[i] == ' ') i++;
                    temp += s[i];
                    i++;
                }
                ans += stoi(temp)*f;
            }
            else if(s[i] == '+'){
                f = 1;
                i++;
            }
            else if(s[i] == '-'){
                f = -1;
                i++;
            }
            else if(s[i]== '(') {
                i++;
                ans += bracketSol(s, i)*f;
                i++;
            }
        }
        return ans;
    }
    int bracketSol(string s, int &i){
        int n = s.length();
        int ans = 0;
        int f = 1;

        while(s[i] != ')'){
            if(s[i] == ' ') i++;
            
            if(s[i] >= '0' && s[i] <= '9'){
                string temp = "";
                while(i < n && s[i] >='0' && s[i] <= '9'){
                    if(s[i] == ' ') i++;
                    temp += s[i];
                    i++;
                }
                ans += stoi(temp)*f;
            }
            else if(s[i] == '+'){
                f = 1;
                i++;
            }
            else if(s[i] == '-'){
                f = -1;
                i++;
            }
            else if(s[i]== '(') {
                i++;
                ans += bracketSol(s, i)*f;
                i++;
            }
        }
        return ans;
    }
};
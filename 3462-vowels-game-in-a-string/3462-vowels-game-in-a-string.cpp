class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;

        for(auto ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count++;
        }

        if(count == 0) return false;
        return true;
    }
};
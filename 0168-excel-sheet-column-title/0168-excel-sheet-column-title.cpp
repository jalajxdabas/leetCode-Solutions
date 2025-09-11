class Solution {
public:
    string convertToTitle(int num) {
        string ans = "";

        while(num > 0){
            num--;
            char ch = num%26 + 'A';
            ans = ch + ans;
            num /= 26;
        }
        return ans;
    }
};
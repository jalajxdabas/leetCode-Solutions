class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;

        bool vowel = false;
        bool consonant = false;

        for(int i=0; i<n; i++){
            char ch = word[i];

            if(ch >= '0' && ch <= '9') continue;

            else if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <= 'Z')){
                if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                    ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowel = true;
                }
                else consonant = true;
            }

            else return false;
        }
        return (vowel & consonant);
    }
};
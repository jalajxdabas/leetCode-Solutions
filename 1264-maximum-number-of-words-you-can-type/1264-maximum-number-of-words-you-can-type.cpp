class Solution {
public:
    bool check(string word, unordered_set<char> &st){

        for(char ch: word){
            if(st.find(ch) != st.end()) return false;
        }
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;

        for(char ch: brokenLetters){
            st.insert(ch);
        }

        int n = text.length();
        int count = 0;

        for(int i=0; i<n; i++){
            string temp = "";

            while(i < n && text[i] != ' '){
                temp += text[i];
                i++;
            }

            if(check(temp, st)) count++;

        }

        return count;
    }
};
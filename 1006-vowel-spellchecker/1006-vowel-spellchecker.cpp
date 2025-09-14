class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, string> capital;
    unordered_map<string, string> vowel;

    string removeVowel(string s){
        string ans = s;
        for(int i=0; i<s.length(); i++){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'o' || ans[i] == 'i' || ans[i] == 'u') ans[i] = '*';
        }
        return ans;
    }

    string toLower(string s){
        string ans = s;

        for(auto &ch: ans) ch = tolower(ch);

        return ans;
    }

    string solve(string s){
        if(st.find(s) != st.end()) return s;

        string temp = toLower(s);
        if(capital.find(temp) != capital.end()) return capital[temp];

        temp = temp = removeVowel(toLower(s));
         if(vowel.find(temp) != vowel.end()) return vowel[temp];

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        st.clear();
        capital.clear();
        vowel.clear();


        for(auto s: wordlist){

            st.insert(s);

            string lower = toLower(s);
            if(capital.find(lower) == capital.end()) capital[lower] = s;

            string temp = removeVowel(toLower(s));

            if(vowel.find(temp) == vowel.end()) vowel[temp] = s;

        }

        vector<string> ans;

        for(auto s: queries){
            string temp = solve(s);

            ans.push_back(temp);
        }
        return ans;
    }
};
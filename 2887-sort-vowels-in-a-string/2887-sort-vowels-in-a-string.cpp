class Solution {
public:
    string sortVowels(string s) {
        vector<char> arr;

        for(auto ch: s){
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') arr.push_back(ch);
        }

        sort(arr.begin(), arr.end());

        int j = 0;
        int n = s.length();

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                s[i] = arr[j];
                j++;
            }
        }
        return s;
        

    }
};
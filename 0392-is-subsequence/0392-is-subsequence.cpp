class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length();
        int pl = t.length();

        if(sl > pl) return false;
        if(sl == pl) return s == t;
        int temp = 0;

        for(int i=0; i<pl; i++){
            if(t[i] == s[temp]) temp++;
            if(temp == sl) return true;
        }
        return false;
        
    }
};
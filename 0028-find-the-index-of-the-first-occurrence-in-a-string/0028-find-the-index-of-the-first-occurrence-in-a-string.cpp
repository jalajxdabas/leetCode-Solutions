class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = haystack.length();
        int b = needle.length();

        if(a < b) return -1;

        for(int i=0; i<=(a-b); i++){
            if(haystack.substr(i, b) == needle) return i;
        }
        return -1;
    }
};
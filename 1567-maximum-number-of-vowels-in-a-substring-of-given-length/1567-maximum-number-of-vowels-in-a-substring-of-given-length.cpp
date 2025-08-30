class Solution {
public:
    bool check(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch=='o' || ch == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = INT_MIN;

        for(int i=0; i<k; i++){
            if(check(s[i])) count++;
        }

        ans = max(ans, count);
        int left = 0;
        int right = k-1;

        while(right < s.length() - 1){
            if(check(s[left])) count--;
            left++;
            ++right;

            if(check(s[right])) count++;

            ans = max(ans, count);
        }
        return ans;



    }
};
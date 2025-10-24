class Solution {
public:
    vector<int> count{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int backtrack(int n, int curr, int digits){
        if(digits == 0){
            for(int i=0; i<=9; i++){
                if(count[i] != 0 && count[i] != i ) return 0;
            }
            return curr > n ? curr : 0;
        }

        int result = 0;
        for(int i = 1; i<=9; i++){
            if(count[i] > 0 && count[i] <= digits){
                count[i]--;
                result = backtrack(n, curr*10+i, digits-1);
                count[i]++;
            }
            if(result != 0) break;
        }
        return result;



    }
    int nextBeautifulNumber(int n) {
        int numDigits = to_string(n).length();

        int result = backtrack(n, 0, numDigits);

        if(result == 0){
            result = backtrack(n, 0, numDigits+1);
        }
        return result;
    }
};
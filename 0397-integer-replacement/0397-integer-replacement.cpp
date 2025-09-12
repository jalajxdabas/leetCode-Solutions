class Solution {
public:
    int integerReplacement(int num) {
        long long n = num;
        int count = 0;
        while(n > 1){
            if(n == 3) n--;
            else if(n%2 == 0) n /= 2;
            else if(n%4 == 1) n--;
            else n++;

            count++;
        }
        return count;
    }
};
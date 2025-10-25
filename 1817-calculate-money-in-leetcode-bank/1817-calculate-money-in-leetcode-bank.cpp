class Solution {
public:
    int totalMoney(int n) {
        int start = 1;
        int sum = 28;
        int count = 0;

        while(n > 7){
            n -= 7;
            count += sum;
            sum += 7;
            start++;
        }

        while(n){
            count += start;
            start++;
            n--;
        }
        return count;


    }
};
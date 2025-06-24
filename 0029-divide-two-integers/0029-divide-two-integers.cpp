class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool sign = true;
        int ans = 0;
        if(dividend >= 0 && divisor < 0) sign = false;
        else if(dividend <= 0 && divisor > 0) sign = false;

        long n = labs(dividend);
        long d = labs(divisor);

        while(n >= d){
            int count = 0;
            while(n >= (d<<(count+1))) count++;
            ans += (1<<count);
            n -= (d<<(count));
        }

        if(ans == (1<<31) && sign == true) return INT_MAX;
        if(ans == (1<<31) && sign == false) return INT_MIN;

        return (sign ? ans : -ans);
    }
};
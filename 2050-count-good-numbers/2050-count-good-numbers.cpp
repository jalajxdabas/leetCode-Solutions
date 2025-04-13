class Solution {
public:
    const int M = 1e9+7;
    long long power(long long a, long long b){
        if(b == 0) return 1;
        long long half = power(a, b/2);
        long long result = (half * half) % M;

        if(b%2 == 1) result = (result * a)%M;
        return result; 

    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (long long)((power(5, even) * power(4, odd)) % M);

    }
};
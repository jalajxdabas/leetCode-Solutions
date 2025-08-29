class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd1 = (n+1)/2;
        long long odd2 = (m+1)/2;

        long long even1 = n-odd1;
        long long even2 = m-odd2;

        long long ans = 0;
        ans += (odd1*even2);
        ans += (odd2 * even1);

        return ans;
    }
};
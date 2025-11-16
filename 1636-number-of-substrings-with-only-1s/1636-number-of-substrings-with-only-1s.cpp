class Solution {
public:
    int MOD = 1e9+7;
    using ll = long long;
    int numSub(string s) {
        ll ans = 0;
        ll count = 0;

        for(auto ch: s){
            if(ch == '1'){
                count++;
            }
            else{
                ans = (ans + (count)*(count+1)/2 ) % MOD;
                count = 0;

            }
        }
        ans = (ans + (count)*(count+1)/2 ) % MOD;
        return ans;
    }
};
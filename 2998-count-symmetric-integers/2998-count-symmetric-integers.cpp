class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low; i<=high; i++){
            string s = to_string(i);

            int l = s.length();
            if(l%2 != 0) continue;

            int leftSum = 0;
            int rightSum = 0;

            for(int i=0; i<l/2; i++){
                leftSum += s[i]-'0';
            }

            for(int i=l/2; i<l; i++){
                rightSum += s[i]-'0';
            }

            if(leftSum == rightSum) ans++;
        }
        return ans;
    }
};
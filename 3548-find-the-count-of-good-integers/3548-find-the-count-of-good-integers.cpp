class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> s;
        int d = (n+1)/2;

        int start = pow(10, d-1);
        int end = pow(10, d) - 1;
        long long result = 0;

        for(int num = start; num<=end; num++){
            string leftHalf = to_string(num);
            string full = "";

            if(n%2 == 0){
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }
            else{
                string rightHalf = leftHalf.substr(0, d-1);
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }

            long long temp = stoll(full);
            if(temp % k != 0) continue;
            else{
                sort(full.begin(), full.end());
                s.insert(full);
            }
        }

        vector<long long> fact(11, 1);
        for(int i=1; i<11; i++){
            fact[i] = fact[i-1]*i;
        }

        for(const string &temp: s){
            vector<int> count(10, 0);
            for(const char &ch: temp){
                count[ch-'0']++;
            }

            int totalDigits = temp.length();
            int zeroDigits = count[0];
            int nonZero = totalDigits-zeroDigits;

            long long prem = (nonZero * fact[totalDigits-1]);

            for(int i=0; i<10; i++){
                prem /= fact[count[i]];
            }

            result += prem;

        }
        return result;
    }
};
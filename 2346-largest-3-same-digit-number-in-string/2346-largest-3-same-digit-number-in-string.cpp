class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string ans;
        int maxi = INT_MIN;

        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                
                if(maxi < num[i]-'0'){
                    ans = num.substr(i, 3);
                    maxi = num[i]-'0';
                }
                i = i+2;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> arr(26, 0);
        for(char &ch: s){
            arr[ch - 'a']++;
        }

        for(int count = 1; count<=t; count++){
            vector<int> temp(26, 0);

            for(int i=0; i<26; i++){
                char ch = i + 'a';
                int freq = arr[i];

                if(ch != 'z'){
                    temp[(ch - 'a')+1] = (freq + temp[(ch - 'a')+1])%M;
                } 
                else{
                    temp[0] = (temp[0] + freq)%M;
                    temp[1] = (temp[1] + freq)%M;
                }
            }

            arr = temp;
        }

        int ans = 0;
        for(int i=0; i<26; i++){
            ans = (ans + arr[i])%M;
        }
        return ans;

    }
};
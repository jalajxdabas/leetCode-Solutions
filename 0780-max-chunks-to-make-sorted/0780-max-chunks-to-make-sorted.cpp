class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(arr.begin(), arr.end());  //prefixMax
        vector<int> suffix(arr.begin(), arr.end());  //suffixMax

        for(int i=1; i<n; i++){
            prefix[i] = max(prefix[i-1], prefix[i]);
        }

        for(int i=n-2; i>=0; i--){
            suffix[i] = min(suffix[i], suffix[i+1]);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            int pehleKaMax = i > 0 ? prefix[i-1] : -1;
            int baadKaMin = suffix[i];

            if(pehleKaMax < baadKaMin) count++;
        }
        return count;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefixMax(arr.begin(), arr.end());
        vector<int> suffixMin(arr.begin(), arr.end());

        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(suffixMin[i], suffixMin[i+1]);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            int leftMax = i > 0? prefixMax[i-1] : -1;
            int rightMin = suffixMin[i];

            if(leftMax <= rightMin) count++;
        }
        return count;
    }
};
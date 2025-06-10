class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int curr = 0;
        int original = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            curr += arr[i];
            original += i;

            if(curr == original) count++;
        }
        return count;
    }
};
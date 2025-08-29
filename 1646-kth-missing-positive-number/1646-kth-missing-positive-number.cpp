class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 1;
        int i = 0;

        while (k > 0) {
            if (i < arr.size() && arr[i] == count) {
                i++;  
            } else {
                k--;  
                if (k == 0) return count;
            }
            count++;
        }

        return count;
    }
};

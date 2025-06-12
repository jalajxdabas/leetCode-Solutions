class Solution {
public:
    int maxAdjacentDistance(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1e9;
        for(int i=1; i<n+1; i++){
            maxi = max(maxi, abs(arr[(i-1)%n] - arr[i%n]));
        }
        return maxi;
    }
};
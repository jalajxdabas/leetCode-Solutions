class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for(int i=0; i<n; i++){
            int num = arr[i];
            int count = 1;

            while(i + 1 < n && arr[i + 1] == num){
                count++;
                i++;
            }

            if(count == num) ans = max(ans, num);
        }
        return ans;
    }
};
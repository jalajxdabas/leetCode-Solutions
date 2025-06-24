class Solution {
public:
    bool isPossible(vector<int> &weights, int days, int mid){
        int count = 1;
        int sum = 0;
        for(int &i: weights){
            if(sum + i > mid) {
                count++;
                sum = i;
                if(count > days) return false;
            }
            else sum += i;

        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int mini = 0;
        int maxi = 0;

        for(int &i: weights){
            mini = max(mini, i);
            maxi += i;
        }
        int ans = -1;

        while(mini <= maxi){
            int mid = mini + (maxi-mini)/2;
            if(isPossible(weights, days, mid)){
                ans = mid;
                
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }
        return ans;
    }
};
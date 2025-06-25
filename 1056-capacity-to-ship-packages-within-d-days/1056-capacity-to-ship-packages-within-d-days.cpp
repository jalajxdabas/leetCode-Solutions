class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = 0;
        int e = 0;
        int ans = -1;

        for(int &i: weights){
            s = max(s, i);
            e += i;
        }

        while(s <= e){
            int mid = s + (e-s)/2;

            if(isPossible(weights, days, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    bool isPossible(vector<int> &weights, int days, int mid){
        int sum = 0;
        int count = 1;

        for(int &i: weights){
            if(sum + i <= mid) sum += i;
            else{
                count++;
                sum = i;
            }
        }
        if(count <= days) return true;
        return false;
    }
};
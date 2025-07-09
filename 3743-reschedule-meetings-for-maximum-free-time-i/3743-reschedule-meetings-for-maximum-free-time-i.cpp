class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free;
        int n = startTime.size();
        free.push_back(startTime[0]);

        for(int i=1; i<startTime.size(); i++){
            free.push_back(startTime[i] - endTime[i-1]);
        }

        free.push_back(eventTime - endTime[n-1]);


        int i = 0;
        int j = 0;
        int maxi = 0;
        int curr = 0;

        while(j <= n){
            curr += free[j];

            while(j-i+1 > k+1 && i<=n){
                curr -= free[i];
                i++;
            }

            maxi = max(maxi, curr);
            j++;
        }
        return maxi;
    }
};
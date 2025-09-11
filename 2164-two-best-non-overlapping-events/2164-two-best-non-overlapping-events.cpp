class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end(), [](const vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        vector<int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2];

        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(events[i][2], suffixMax[i+1]);
        }

        int maxi = 0;
        for(int i=0; i<n; i++){
            int left = i+1;
            int right = n-1;

            int next = -1;

            while(left <= right){
                int mid = left + (right-left)/2;

                if(events[mid][0] > events[i][1]){
                    next = mid;
                    right = mid-1;
                }
                else left = mid+1;

                


            }

            if(next != -1){
                maxi = max(maxi, events[i][2] + suffixMax[next]);
            }

            maxi = max(maxi, events[i][2]);
        }
        return maxi;
    }
};
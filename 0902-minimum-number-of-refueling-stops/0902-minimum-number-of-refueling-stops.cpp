class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        stations.push_back({target, 0});

        priority_queue<int> pq;

        for(int i=0; i<stations.size(); i++){
            if(startFuel < stations[i][0]){
                while(!pq.empty() && startFuel < stations[i][0]){
                    startFuel += pq.top();
                    pq.pop();
                    ans++;
                }
            }
            if(startFuel < stations[i][0]) return -1;

            pq.push(stations[i][1]);
        }
        return ans;
    }
};
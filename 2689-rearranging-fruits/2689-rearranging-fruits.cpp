class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;

        for(auto &i: basket1){
            mp[i]++;
            mini = min(mini, i);
        }

        for(auto &i: basket2) {
            mp[i]--;
            mini = min(mini, i);
        }


        vector<int> finalList;

        for(auto &it: mp){
            int cost = it.first;
            int count = abs(it.second);

            if(count == 0) continue;

            if(count % 2 != 0) return -1;

            else{
                for(int c=1; c<=count/2; c++){
                    finalList.push_back(cost);
                }
            }
        }

        sort(finalList.begin(), finalList.end());

        long long ans = 0;

        int n = finalList.size();

        for(int i=0; i<n/2; i++){
            ans += min(finalList[i], mini*2);
        }
        return ans;

    }
};
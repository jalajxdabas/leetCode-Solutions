class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            int curr = intervals[i][0];
            int n = ans.size();

            if(curr <= ans[n-1][1]){
                ans[n-1][1] = max(ans[n-1][1], intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
        }

        return ans;
    }
};
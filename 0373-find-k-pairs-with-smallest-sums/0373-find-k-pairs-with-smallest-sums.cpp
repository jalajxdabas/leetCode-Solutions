class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> mini;

        for(int i=0; i<nums1.size() && i<k; i++){
            mini.emplace(nums1[i] + nums2[0], i, 0);
        }

        while(k-- && !mini.empty()){
            auto[sum, i, j] = mini.top();
            mini.pop();
            ans.push_back({nums1[i], nums2[j]});

            if(j+1<nums2.size()){
                mini.emplace(nums1[i]+nums2[j+1], i, j+1);
            }
        }
        return ans;
    }
};
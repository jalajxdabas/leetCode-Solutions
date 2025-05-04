class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> temp(100);

        int result = 0;

        for(auto &d: dominoes){
            if(d[0] > d[1]) swap(d[0], d[1]);

            int val = d[0]*10 + d[1];

            result += temp[val]++;
        }
        return result;
    }
};
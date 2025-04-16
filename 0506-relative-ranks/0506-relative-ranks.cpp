class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        auto comp = [](pair<int, int> &a, pair<int, int> &b){
            return a.second<b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> maxi(comp);

        for(int i=0; i<score.size(); i++){
            maxi.push({i, score[i]});
        }

        int place = 0;
        while(!maxi.empty()){
            pair<int, int> p = maxi.top();
            maxi.pop();
            place++;
            if(place == 1){
                ans[p.first] = ("Gold Medal");
            }
            else if(place == 2){
                ans[p.first] = ("Silver Medal");
            }
            else if(place == 3){
                ans[p.first] = ("Bronze Medal");
            }
            else{
                ans[p.first] = (to_string(place));
            }
        }
        return ans;
    }
};
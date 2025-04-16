class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;

        unordered_map<int, string> mp;
        priority_queue<int> maxi;
        for(int &i: score){
            maxi.push(i);
        }

        int i=1;
        while(!maxi.empty()){
            if(i == 1){
                mp[maxi.top()] = "Gold Medal";
                i++;
            }
            else if(i == 2){
                mp[maxi.top()] = "Silver Medal";
                i++;
            }
            else if(i == 3){
                mp[maxi.top()] = "Bronze Medal";
                i++;
            }
            else{
                mp[maxi.top()] = to_string(i);
                i++;
            }
            maxi.pop();
        }
        for(int i=0; i<score.size(); i++){
            ans.push_back(mp[score[i]]);
        }
        return ans;
    }
};
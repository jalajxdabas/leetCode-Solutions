class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        
        string s = "0000";
        queue<pair<string, int>> q;
        int ans = INT_MAX;

        q.push({s, 0});
        vis.insert(s);

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            string curr = top.first;
            int steps = top.second;

            if(st.count(curr)) continue;

            if(curr == target){
                ans = min(ans, steps);
                continue;
            }

            
            for(int i=0; i<4; i++){
                char temp = curr[i];
                curr[i] = ((curr[i] - '0' + 1)%10) + '0';
                if(!vis.count(curr)){
                    q.push({curr, steps+1});
                    vis.insert(curr);
                }
                curr[i] = temp;
            }
            for(int i=0; i<4; i++){
                char temp = curr[i];
                curr[i] = ((curr[i] - '0' - 1 + 10)%10) + '0';
                if(!vis.count(curr)){
                    q.push({curr, steps+1});
                    vis.insert(curr);
                }
                curr[i] = temp;
            }
            


        }
        if(ans == INT_MAX) return -1;
        return ans;

    }
};
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prev = 0;
        int curr = 0;
        int ans = 0;

        for(auto s: bank){
            int n = s.size();
            if(prev == 0){
                for(auto ch: s){
                    if(ch == '1') prev++;
                }
                continue;
            }

            for(auto ch: s){
                if(ch == '1') curr++;
            }

            // cout<<prev<<" "<<curr<<endl;

            if(prev > 0 && curr > 0){
                ans += (prev*curr);
                prev = curr;
                curr = 0;
            }
        }
        return ans;

    }
};
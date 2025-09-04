class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.length();
        unordered_map<char, int> last;

        for(int i=0; i<n; i++){
            char ch = s[i];
            last[ch] = i;
        }

        
        int end = 0;
        int start = -1;
        for(int i=0; i<n; i++){
            char ch = s[i];
            end = max(end, last[ch]);
            if(i == end){
                ans.push_back(end-start);
                start = end;
            }
        }

        if(ans.size() == 0) ans.push_back(n);

        return ans;


    }
};
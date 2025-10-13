class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        string s;
        for(int i=0; i<n; i++){
            if(i == 0){
                s = words[i];
                ans.push_back(s);
                sort(s.begin(), s.end());  
                continue;
            }

            string temp = words[i];
            sort(temp.begin(), temp.end());

            if(s == temp) continue;
            else{
                s = temp;
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty() || s.empty()) return ans;
        unordered_map<string, int> map;
        int n = words.size();

        for(int i=0; i<n; i++) map[words[i]]++;

        int len = words[0].length();
        int total = n*len;

       for(int i=0; i<len; i++){
            int left = i; int count = 0;
            unordered_map<string, int> seen;

            for(int right = i; right+len <= s.length(); right += len){
                string word = s.substr(right, len);

                if(map.find(word) != map.end()){
                    count++;
                    seen[word]++;
                

                    while(seen[word] > map[word]){
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        left += len;
                        count--;
                    }

                    if(count == n){
                        ans.push_back(left);
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        left += len;
                        count--;
                    }
                }
                else{
                    seen.clear();
                    count = 0;
                    left = right+len;
                }
            }


       }

        
        return ans;

    }
};
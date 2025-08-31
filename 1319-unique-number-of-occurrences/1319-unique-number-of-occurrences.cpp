class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(int i: arr){
            mp[i]++;
        }

        for(auto i: mp){
            int freq = i.second;
            if(st.find(freq) != st.end()) return false;
            st.insert(freq);

        }
        return true;


    }
};
class Solution {
public:
    void dfs(int i, unordered_set<int> &st, vector<vector<int>> &rooms){
        vector<int> temp = rooms[i];

        for(auto i: temp){
            if(st.find(i) == st.end()){
                st.insert(i);
                dfs(i, st, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> st;
        st.insert(0);

        dfs(0, st, rooms);

        if(st.size() == rooms.size()) return true;
        return false;


    }
};
class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int> &path, stack<int> &st, vector<int> adj[]){
        vis[i] = 1;
        path[i] = 1;

        for(auto &it: adj[i]){
            if(!vis[it]){
                (dfs(it, vis, path, st, adj));
            }
            else if(path[it]) return false;
            else {continue;}
        }

        st.push(i);
        path[i] = 0;
        return true;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for(auto &i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        stack<int> st;
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(!dfs(i, vis, path, st, adj)) return {};
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        if(ans.size() == n) return ans;

        return {};

    }
};
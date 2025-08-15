class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int> &path, vector<int> adj[]){

        
        vis[i] = 1;
        path[i] = 1;

        for(auto &x : adj[i]){
            if(!vis[x]){
                if(dfs(x, vis, path, adj)){
                    return true;
                }
            }
            else if(path[x] == 1) return true;
        }

        path[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];

        for(auto &i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0);
        vector<int> path(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, vis, path, adj)) return false;
            }
        }

        return true;
    }
};
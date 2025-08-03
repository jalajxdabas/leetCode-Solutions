class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int> &pathvis, vector<int> adj[]){
        vis[i] = 1;
        pathvis[i] = 1;

        for(auto it: adj[i]){
            if(!vis[it]){
                if(dfs(it, vis, pathvis, adj)){
                return true;
                }
            }else if(pathvis[it]){
                return true;
            }
        }

        pathvis[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);

        vector<int> adj[n];
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathvis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
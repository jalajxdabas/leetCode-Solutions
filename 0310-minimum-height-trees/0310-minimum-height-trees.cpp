class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};

        vector<int> indegree(n, 0);
        vector<int> adj[n];

        for(auto &it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1) q.push(i);
        }

        int count = 0;

        while(n-count > 2){
            int size = q.size();
            count += size;

            for(int i=0; i<size; i++){
                int top = q.front();
                q.pop();

                for(auto j: adj[top]){
                    if(--indegree[j] == 1) q.push(j);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
};
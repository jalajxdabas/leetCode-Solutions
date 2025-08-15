class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for(auto &i: prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(auto &i: adj[top]){
                if(--indegree[i] == 0) q.push(i);
            }
        }

        if(ans.size() == n) return ans;

        return {};


    }
};
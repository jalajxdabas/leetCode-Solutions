class Solution {
public:
    void bfs(int i, vector<int> temp, vector<vector<int>> &ans, vector<vector<int>>& graph){
        if(i == graph.size()-1){
            ans.push_back(temp);
            return;
        }

        for(auto adj: graph[i]){
            temp.push_back(adj);
            bfs(adj, temp, ans, graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        temp.push_back(0);

        bfs(0, temp, ans, graph);

        return ans;
    }
};
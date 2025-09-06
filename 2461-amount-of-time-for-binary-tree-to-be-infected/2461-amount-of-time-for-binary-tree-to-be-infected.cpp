/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    void constructGraph(TreeNode* root){
        if(!root) return;

        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        int ans = -1;
        queue<int> q;
        q.push(start);

        unordered_set<int> st;

        while(!q.empty()){
            ++ans;

            int n = q.size();
            for(int i=0; i<n; i++){
                int top = q.front();
                q.pop();
                st.insert(top);

                for(int adj: graph[top]){
                    if(!st.count(adj)){
                        q.push(adj);
                    }
                }
            }

        }
        return ans;


    }
};
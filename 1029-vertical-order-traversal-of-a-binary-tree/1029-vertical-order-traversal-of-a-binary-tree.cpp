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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            TreeNode* front = top.first;
            int x = top.second.first;
            int y = top.second.second;

            nodes[x][y].insert(front->val);

            if(front->left) q.push({front->left, {x-1, y+1}});

            if(front->right) q.push({front->right, {x+1, y+1}});

        }

        for(auto &i: nodes){
            vector<int> col;

            for(auto r: i.second){
                col.insert(col.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(col);

        }
        return ans;
    }
};
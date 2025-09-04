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
    void solve(int level, int &reached, TreeNode* root, vector<int> &ans){
        if(root == NULL) return;

        if(level > reached){
            ans.push_back(root->val);
            reached = level;
        }

        solve(level+1, reached, root->right, ans);
        solve(level+1, reached, root->left, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        int reached = -1;
        solve(0, reached, root, ans);
        return ans;
    }
};
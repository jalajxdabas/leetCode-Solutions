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
    void solve(TreeNode* root, int level, int dir,  int &ans){
        ans = max(ans, level);
        if(root == NULL) return;
        

        if(dir == 0){
            if(root->right) solve(root->right, level+1, 1, ans);
            if(root->left) solve(root->left, 1, 0, ans);
        }
        else{
            if(root->left)  solve(root->left, level+1, 0, ans);
            if(root->right) solve(root->right, 1, 1, ans);
        }

    }
    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, 0, 0, ans);
        return ans;
    }
};
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
    int solve(TreeNode* root, int level){
        if(root == NULL) return 0;
        level = level +1;

        return max(level,  max(solve(root->left, level), solve(root->right, level)));
    }
    int maxDepth(TreeNode* root) {
        return solve(root, 0);
    }
};
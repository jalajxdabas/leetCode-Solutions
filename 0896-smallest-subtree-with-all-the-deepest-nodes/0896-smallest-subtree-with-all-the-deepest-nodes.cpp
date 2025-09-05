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

    TreeNode* solve(TreeNode* root, int curr, int depth){
        if(curr == depth) {
            return root;
        }

        if(root == NULL) return root;

        curr = curr+1;

        TreeNode* left = solve(root->left, curr, depth);
        TreeNode* right = solve(root->right, curr, depth);

        if(left && right) return root;

        if(left == NULL) return right;

        return left;
    }

    int findDepth(TreeNode* root, int level){
        if(root == NULL) return 0;

        level = level+1;
        return max(level, max(findDepth(root->left, level), findDepth(root->right, level)));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = findDepth(root, 0);

        return solve(root, 0, depth-1);
    }
};
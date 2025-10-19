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
    void findDepth(TreeNode* root, int reached, int &level){
        if(root == NULL) return;
        if(reached > level) level = reached;
        

        if(root->left) findDepth(root->left, reached+1, level);
        if(root->right) findDepth(root->right, reached+1, level);
    }

    TreeNode* solve(TreeNode* root, int curr, int depth){
        if(root == NULL) return NULL; 
        if(curr == depth) return root;


        TreeNode* left = solve(root->left, curr+1, depth);
        TreeNode* right = solve(root->right, curr+1, depth);

        if(left && right) return root;

        return left ? left: right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = 0;
        findDepth(root, 0, depth);

        int curr = 0;
        return solve(root, curr, depth);
    }
};
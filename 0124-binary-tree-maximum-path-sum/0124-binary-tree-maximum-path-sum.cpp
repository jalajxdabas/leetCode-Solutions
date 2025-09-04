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
    int solve(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        int leftSum = max(0, solve(root->left, maxi));
        int rightSum = max(0, solve(root->right, maxi));
        int total = leftSum + rightSum + root->val;

        maxi = max(maxi, total);

        int maxPath = max(leftSum, rightSum) + root->val;
        return maxPath;



    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        solve(root, maxi);
        return maxi;
    }
};
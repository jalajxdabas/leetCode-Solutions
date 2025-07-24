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
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(root == NULL) return true;

        bool curr = (root->val > mini && root->val < maxi);

        return curr && solve(root->left, mini, root->val) && solve(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        long long mini = LONG_MIN;
        long long maxi = LONG_MAX;
        return solve(root, mini, maxi);
    }
};
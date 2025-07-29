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
    class data{
        public:
        bool isValid;
        int mini;
        int maxi;
        int sum;

        data(bool isValid, int mini, int maxi, int sum){
            this->isValid = isValid;
            this->mini = mini;
            this->maxi = maxi;
            this->sum = sum;
        }
    };
    int ans = 0;

    data solve(TreeNode* root){
        if(root == NULL){
            return data(true, 1e9, -1e9, 0);
        }

        data left = solve(root->left);
        data right = solve(root->right);

        if(left.isValid && right.isValid && left.maxi < root->val && right.mini > root->val){
            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);
            int mini = min(root->val, left.mini);
            int maxi = max(root->val, right.maxi);
            return data(true, mini, maxi, sum);
        }
        return data(false, 1e9, -1e9, 0);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
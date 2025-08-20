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
    void solve(TreeNode* root, string ans, int &sum){
        ans += to_string(root->val);
        if(root == NULL) return;
        if(!root->left && !root->right){
            sum += stoi(ans);
            return;
        }

        if(root->left) solve(root->left, ans, sum);
        if(root->right) solve(root->right, ans, sum);
    }
    int sumNumbers(TreeNode* root) {
        string ans = "";
        int sum = 0;

        solve(root, ans, sum);

        return sum;

    }
};
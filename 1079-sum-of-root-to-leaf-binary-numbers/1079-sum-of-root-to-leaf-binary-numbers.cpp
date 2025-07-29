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
    vector<vector<int>> nums;

    void solve(TreeNode* root, vector<int> temp){
        if(root == NULL) return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            nums.push_back(temp);
            return;
        }
        solve(root->left, temp);
        solve(root->right, temp);
    }

    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;

        vector<int> temp;
        solve(root, temp);

        int sum = 0;
        for (auto &path : nums) {
            int num = 0;
            for (auto &bit : path) {
                num = (num << 1) | bit;
            }
            sum += num;
        }
        return sum;
    }
};
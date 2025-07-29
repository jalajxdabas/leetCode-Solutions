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
    
    void getMax(TreeNode* root, int level, int &maxi){
        if(root == NULL){
            return;
        }
        maxi = max(level, maxi);

        if(root->left) getMax(root->left, level+1, maxi);
        if(root->right) getMax(root->right, level+1, maxi);
    }

    void solve(TreeNode* root, int level, int maxi, int &sum){
        if(root == NULL) return;
        if(level == maxi){
            sum += root->val;
            return;
        }
        solve(root->left, level+1,maxi, sum);
        solve(root->right, level+1,maxi, sum);
    }


    int deepestLeavesSum(TreeNode* root) {
        int maxi = 0;
        getMax(root, 1, maxi);

        int sum = 0;
        solve(root, 1, maxi, sum);
        return sum;
    }
};
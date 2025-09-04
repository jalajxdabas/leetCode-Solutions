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
    bool check(vector<int> path){
        int odd = 0;

        for(auto i: path){
            if(i % 2 == 1) odd++;
        }

        if(odd > 1) return false;
        return true;
    }
    void solve(TreeNode* root, vector<int> path, int &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            path[root->val]++;
            if(check(path)){
                ans++;
                return;
            }
            return;
        }

        path[root->val]++;
        solve(root->left, path, ans);
        solve(root->right, path, ans);
    } 
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path(10, 0);
        int ans = 0;

        solve(root, path, ans);

        return ans;


    }
};
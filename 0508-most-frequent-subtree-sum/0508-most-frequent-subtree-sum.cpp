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
    unordered_map<int, int> mp;
    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);
        int sum = left + right + root->val;
        mp[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        int maxi = -1e9;
        for(auto &i: mp){
            maxi = max(maxi, i.second);
        }

        vector<int> ans;
        for(auto &i: mp){
            if(i.second == maxi) ans.push_back(i.first);
        }

        return ans;
    }
};
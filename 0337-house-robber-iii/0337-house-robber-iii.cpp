// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int solve2(TreeNode* root){
        if(!root) return 0;
        if(dp.count(root)) return dp[root];

        int dontRob = solve2(root->left) + solve2(root->right);

        int rob = root->val;
        if(root->left) rob += solve2(root->left->left) + solve2(root->left->right);
        if(root->right) rob += solve2(root->right->left) + solve2(root->right->right);

        return dp[root] = max(dontRob, rob);
    }

    int rob(TreeNode* root) {
        return solve2(root);
    }
};


// class Solution {
// public:
//     pair<int,int> solve(TreeNode* root){
//         if(!root) return {0,0};

//         auto left = solve(root->left);
//         auto right = solve(root->right);

//         int rob = root->val + left.second + right.second;
//         int dontRob = max(left.first, left.second) + max(right.first, right.second);

//         return {rob, dontRob};
//     }

//     int rob(TreeNode* root) {
//         auto res = solve(root);
//         return max(res.first, res.second);
//     }
// };

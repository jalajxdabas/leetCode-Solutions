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

// in INOrder traversal consecutive number will give me smallest diff
    void preOrder(TreeNode* root, int& res, TreeNode*& prev){
        if(!root) return ;

        preOrder(root->left, res, prev) ;

        if(prev != NULL){
            res = min(res, abs(root->val - prev->val)) ;
        }
        prev = root ;
        
        
        preOrder(root->right, res, prev) ;
    }

    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX ;
        TreeNode* prev  = nullptr;
        preOrder(root, res, prev) ;

        return res ;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q) return root;

        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        if(leftAns!= NULL && rightAns != NULL){
            return root;
        }

        if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }

        if(leftAns!=NULL && rightAns == NULL){
            return leftAns;
        }

        else{
            return NULL;
        }

        return NULL;

    }
};
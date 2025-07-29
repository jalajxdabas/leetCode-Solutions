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
    void addNode(TreeNode* root, int val){
        if(root == NULL) return;
        TreeNode* oldLeft = root->left;
        TreeNode* oldRight = root->right;

        TreeNode* temp = new TreeNode(val);

        root->left = new TreeNode(val);
        root->left->left = oldLeft;

        root->right = new TreeNode(val);
        root->right->right = oldRight;


        return;

    }
    void solve(TreeNode* root, int val, int depth){
        if(root == NULL) return;
        if(depth == 0){
            addNode(root, val);
        }
        if(root->left) solve(root->left, val, depth-1);
        if(root->right) solve(root->right, val, depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
         solve(root, val, depth-2);
         return root;
    }
};
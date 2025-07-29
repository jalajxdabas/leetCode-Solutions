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
    int getMax(TreeNode* root){
        
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }

        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }

        else{

            if(!root->left && !root->right){
                delete root;
                return NULL;
            }

            else if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            else if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            else{
                int maxi = getMax(root->left);
                root->val = maxi;
                root->left = deleteNode(root->left, maxi);
            }
        }
        return root;
    }
};
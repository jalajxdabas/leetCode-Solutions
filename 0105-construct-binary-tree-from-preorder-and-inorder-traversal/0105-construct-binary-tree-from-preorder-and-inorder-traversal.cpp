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
    int findPosition(vector<int> &inorder, int start, int end, int ele){
        for(int i=start; i<=end; i++){
            if(inorder[i] == ele) return i;
        }
        return -1;

    }
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &idx, int start, int end, int n){
        if(idx >= n || start > end) return NULL;

        int ele = preorder[idx++];
        int pos = findPosition(inorder, start, end, ele);
        TreeNode* root = new TreeNode(ele);

        root->left = solve(preorder, inorder, idx, start, pos-1, n);
        root->right = solve(preorder, inorder, idx, pos+1, end, n);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        TreeNode* ans = solve(preorder, inorder, idx, 0, n-1, n);
        return ans;
    }
};
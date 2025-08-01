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
    bool solve(TreeNode* root, int level){
        if(root == NULL) return true;

        
    }
    bool isEvenOddTree(TreeNode* root) {
    vector<TreeNode*> q{root};
    int l = -1;
    while (!q.empty()) {
        ++l;
        int val = 0;
        vector<TreeNode*> q1;
        for (auto n : q)
            if (n != nullptr) {
                if (n->val % 2 == l % 2)
                    return false;
                if (val != 0 && ((l % 2 && val <= n->val) || (!(l % 2) && val >= n->val)))
                    return false;           
                val = n->val;
                q1.push_back(n->left);
                q1.push_back(n->right);
            }
        swap(q, q1);
    }
    return true;
}
};
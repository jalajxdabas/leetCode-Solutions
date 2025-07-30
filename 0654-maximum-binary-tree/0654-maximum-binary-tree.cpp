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
    int getMax(int start, int end, vector<int> nums){
        int maxi = -1;
        int idx = -1;

        for(int i=start; i<=end; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                idx = i;
            }
            else continue;
        }

        return idx;
    }
    TreeNode* solve(int start, int end, vector<int> &nums){
        if(start > end) return NULL;

        int index = getMax(start, end, nums);
        
        TreeNode* root = new TreeNode(nums[index]);
        root->left = solve(start, index-1, nums);
        root->right = solve(index+1, end, nums);
        return root;


    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = solve(0, n-1, nums);
        return root;
    }
};
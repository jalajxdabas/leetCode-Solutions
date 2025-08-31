class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> path;
        return dfs(root, targetSum, path);
    }

    int dfs(TreeNode* node, int targetSum, vector<long long>& path) {
        if (!node) return 0;

        path.push_back(node->val);
        long long sum = 0;
        int count = 0;

        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == targetSum) count++;
        }

        count += dfs(node->left, targetSum, path);
        count += dfs(node->right, targetSum, path);

        path.pop_back();
        return count;
    }
};
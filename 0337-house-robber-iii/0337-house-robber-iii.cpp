
class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int solve(TreeNode* root, int& ans) {
        if (!root) return 0;

        if (dp.find(root) != dp.end()) return dp[root];
        // if include
        int include = root->val;
        if (root->left) {
            include += solve(root->left->left, ans) + solve(root->left->right, ans);
        }
        if (root->right) {
            include += solve(root->right->left, ans) + solve(root->right->right, ans);
        }

        int exclude = solve(root->right, ans) + solve(root->left, ans);

        dp[root] = max(include, exclude);
        return dp[root];
    }
    int rob(TreeNode* root) {
        int ans = 0;
        
        return solve(root, ans);
    }
};
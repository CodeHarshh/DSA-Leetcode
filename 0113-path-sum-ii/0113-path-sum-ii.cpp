
class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode* root, int targetSum, vector<int>& curr_path) {
        if (root == NULL) return;

        curr_path.push_back(root->val);

        if (!root->left && !root->right) {
            if (targetSum == root->val)
                ans.push_back(curr_path);
        }

        solve(root->left, targetSum - (root->val), curr_path);
        solve(root->right, targetSum - (root->val), curr_path);

        curr_path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr_path;
        solve(root, targetSum, curr_path);

        return ans;
    }
};
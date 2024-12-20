
class Solution {
public:
    bool solve(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;

        bool l = solve(left->left, right->right);
        bool r = solve(left->right, right->left);
        return l && r;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return (solve(root->left, root->right));
    }
};
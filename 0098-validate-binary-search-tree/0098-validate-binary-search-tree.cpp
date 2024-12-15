
class Solution {
public:
    bool solve(TreeNode* root, long long min, long long max) {
        if (!root) return true;
        if(root->val <= min || root ->val >= max) return false;

        bool leftside = solve(root->left,min,root->val);
        bool rightside = solve(root->right,root->val,max);
        return leftside && rightside;
    }
    bool isValidBST(TreeNode* root) {
        long long min=LLONG_MIN , max=LLONG_MAX;
        return solve(root,min,max);
    }
};
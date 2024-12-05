
class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int maxHeight = max(lh, rh);
        return maxHeight + 1;
    }
    bool isBalanced(TreeNode* root) {

        if (root == NULL)
            return true;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        int diff = abs(lh - rh);
        bool status = diff <= 1;

        return status&& isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int d = 0;
        solve(root, d);
        return d;
    }

    int solve(TreeNode* root, int& d) {
        if (root == NULL)
            return 0;
        int leftsubtree = solve(root->left, d);
        int rightsubtree = solve(root->right, d);

        d = max(d, leftsubtree + rightsubtree);
        return max(leftsubtree, rightsubtree) + 1;
    }
};
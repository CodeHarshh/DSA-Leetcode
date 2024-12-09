
class Solution {
    // public:
    ///////// m1 - o(n^2)
    // int getHeight(TreeNode* root) {
    //     if (root == NULL) return 0;
    //     int lh = getHeight(root->left);
    //     int rh = getHeight(root->right);
    //     return max(lh, rh) + 1;
    // }

    // bool isBalanced(TreeNode* root) {

    //     if (root == NULL) return true;

    //     int lh = getHeight(root->left);
    //     int rh = getHeight(root->right);

    //     int diff = abs(lh - rh);
    //     bool status = diff <= 1;

    //     return status&& isBalanced(root->left) && isBalanced(root->right);
    // }

    ///// m2 o(N)

public:
    bool isbalanced = true;

    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        if (isbalanced && abs(lh - rh) > 1) {
            isbalanced = false;
        }
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {

        getHeight(root);
        return isbalanced;
    }
};
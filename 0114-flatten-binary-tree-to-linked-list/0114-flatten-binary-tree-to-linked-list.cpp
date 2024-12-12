
class Solution {
public:
    void flatten(TreeNode* root) {
        // using morris traversal ->one left then right right right ....
        if (!root) return;
        while (root != NULL) {
            if (root->left != NULL) {
                TreeNode* leftt = root->left;
                TreeNode* curr = leftt;

                while (curr->right != NULL) {
                    curr = curr->right;
                }
                curr->right = root->right;
                root->left = NULL;
                root->right = leftt;
            }
            root = root->right;
        }
    }
};
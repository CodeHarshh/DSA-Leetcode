
class Solution {
public:
    int minDiff = INT_MAX;

    void inOrder(TreeNode* root, TreeNode*& prev) {
        if (!root) return;
        inOrder(root->left, prev);
        if (prev != NULL) {
            int Diff = (root->val) - (prev->val);
            minDiff = min(Diff, minDiff);
        }
        prev = root;
        inOrder(root->right, prev);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        inOrder(root, prev);
        return minDiff;
    }
};
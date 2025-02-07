
class Solution {
public:
    void inorder(TreeNode* root, int& sum, int& low, int& high) {
        if (!root)
            return;

        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        inorder(root->left, sum, low, high);
        inorder(root->right, sum, low, high);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder(root, sum, low, high);
        return sum;
    }
};
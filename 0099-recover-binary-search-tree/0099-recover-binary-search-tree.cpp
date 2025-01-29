
class Solution {
public:
    // only two nodes are swapped by mistake
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode*& root) {
        if (!root)return;
        inorder(root->left);

        if (prev != NULL && (root->val < prev->val)) { // mean voilation occurs
            if (first == NULL) {                       // first time voilation
                first = prev;
                middle = root;
            } else { // second time voilation
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root)return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        return;
    }

    TreeNode* createTree(vector<int>& v, int s, int e) {
        if (s > e)return NULL;
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = createTree(v, s, mid - 1);
        root->right = createTree(v, mid + 1, e);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        int s = 0;
        inorder(root, v);
        int e = v.size() - 1;
        return createTree(v, s, e);
    }
};
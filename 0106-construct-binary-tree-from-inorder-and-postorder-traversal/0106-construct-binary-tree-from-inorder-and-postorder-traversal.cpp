
class Solution {
public:
    void mapping(vector<int>& inorder, unordered_map<int, int>& m) {
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
    }

    TreeNode* createTree(vector<int>& postorder, vector<int>& inorder, int start,
                         int end, unordered_map<int, int>& m, int &postInd) {
        if (start > end)
            return NULL;
        TreeNode* node = new TreeNode (postorder[postInd--]);
        int pos = m[node->val];
        node->right = createTree(postorder, inorder, pos + 1, end, m,postInd);
        node->left = createTree(postorder, inorder, start, pos - 1, m,postInd);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        mapping(inorder, m);
        int postInd = postorder.size() -1;
        return createTree(postorder, inorder, 0, inorder.size() - 1, m, postInd);
    }
};
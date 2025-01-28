
class BSTIterator {
public:
    stack<TreeNode*> s;

    void pushLeftNode(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) { 
        pushLeftNode(root); 
        }

    int next() {
        auto top = s.top();
        s.pop();

        if (top->right) pushLeftNode(top->right);
        return top->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

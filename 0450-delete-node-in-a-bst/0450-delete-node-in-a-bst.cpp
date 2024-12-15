class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return NULL;}
            
            if (root->left && !root->right) {    // Available only left child
                TreeNode* leftchild = root->left;
                root->left = NULL;
                delete root;
                return leftchild;}

            if (!root->left && root->right) { // Available only right child
                TreeNode* rightchild = root->right;
                root->right = NULL;
                delete root;
                return rightchild;}
            
            if (!root->left && !root->right) { // both right child& left child are not available
                delete root;
                return NULL; }
           

            if (root->left && root->right) { // Available both right child& left child
                TreeNode* temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }

        } else if (root->val > key) root->left = deleteNode(root->left, key);
          else if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
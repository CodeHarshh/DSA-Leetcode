
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (root == NULL)
            return 0;

        int leftsubTree = maxDepth(root->left);
        int RightsubTree = maxDepth(root->right);
        int maxans = max(leftsubTree, RightsubTree);

        return maxans + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        int leftsubtree = diameterOfBinaryTree(root->left);
        int rightsubtree = diameterOfBinaryTree(root->right);
    
        int bothside = maxDepth(root->left) + maxDepth(root->right);
        int maxans=max(leftsubtree,max(rightsubtree,bothside));

        return maxans;
    }
};
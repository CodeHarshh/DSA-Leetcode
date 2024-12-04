
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (root == NULL)
            return 0;

        int leftsubTree = maxDepth(root->left);
        int RightsubTree = maxDepth(root->right);
        int maxans = max(leftsubTree, RightsubTree);
        
        return maxans+1;
    }
};
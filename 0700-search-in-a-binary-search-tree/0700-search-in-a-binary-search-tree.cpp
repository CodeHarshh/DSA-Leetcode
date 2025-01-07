
class Solution {
public:
    TreeNode* searchBST(TreeNode* root , int k) {
        if(!root ) return NULL;
        if (root ->val == k) return root ;
        if (k < root ->val) return searchBST(root  -> left, k);
        else if (k > root ->val) return searchBST(root  ->right, k);
        return root ;
    }
};
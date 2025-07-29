class Solution {
public:

// \U0001f501 Step-by-Step Logic:
// If the current node is NULL, return NULL.
// If the current node is either p or q, return that node.
// Recursively search in the left and right subtrees.
// If both sides return non-NULL, it means p is in one side and q in the other → return current node as LCA.
// If only one side returns non-NULL, return that side (means both nodes are in the same subtree).


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        if(root==p || root==q) return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL &&  right==NULL) return NULL;
        if(left!=NULL &&  right==NULL) return left;
        if(left==NULL &&  right!=NULL) return right;
        return root;
    }
};
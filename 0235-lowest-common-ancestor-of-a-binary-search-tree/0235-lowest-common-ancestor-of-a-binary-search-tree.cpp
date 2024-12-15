

class Solution {
public:
    // solve(TreeNode* root, TreeNode* p, TreeNode* q) {}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if(root== p || root==q) return root;

        if (p->val < root->val && q->val < root->val)
            lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            lowestCommonAncestor(root->right, p, q);

    
            TreeNode* leftside=lowestCommonAncestor(root->left,p,q);
            TreeNode* rightside=lowestCommonAncestor(root->right,p,q);

            if(leftside && rightside) return root;
            // this line just to return something //we can also use 
            // return leftside ? leftside : rightside;

             return rightside ? rightside : leftside;
    }
};
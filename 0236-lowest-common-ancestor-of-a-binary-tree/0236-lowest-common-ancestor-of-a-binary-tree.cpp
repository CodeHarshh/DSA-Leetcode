class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        if(root->val==p->val) return p;
        if(root->val==q->val) return q;

        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);

        if(l==NULL &&  r==NULL) return NULL;
        if(l!=NULL &&  r==NULL) return l;
        if(l==NULL &&  r!=NULL) return r;

        return root;
    }
};
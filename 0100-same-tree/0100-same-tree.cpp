
class Solution {
public:
bool solve(TreeNode* p, TreeNode* q){
    if(!p && !q) return true;
    if(!p) return false;
    if(!q) return false;

    if(p->val != q->val) return false;
    
    bool a=solve(p->left,q->left);
    bool  b=solve(p->right,q->right);
    return a||b;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
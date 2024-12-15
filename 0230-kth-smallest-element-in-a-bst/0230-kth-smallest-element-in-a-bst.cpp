
class Solution {
public:

    void solve(TreeNode* root,vector<int>&v){
    if(! root) return;
     solve(root->left,v);
     v.push_back(root->val);
     solve(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        solve(root,v);
        return v[k-1];
    }
};
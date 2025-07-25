
class Solution {
public:

  void solve (TreeNode* root,  vector<int>&ans){
    if(root==NULL) return ;

    solve(root->left,ans);
    solve(root->right,ans);
    ans.push_back(root->val);

 }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }

  
//    void solve(TreeNode* root, vector<int>& ans) {
//         if (root == NULL)
//             return;

//         solve(root->left, ans);
//         solve(root->right, ans);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         solve(root, ans);
//         return ans;
//     }  


};
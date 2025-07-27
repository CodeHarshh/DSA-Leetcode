
class Solution {
public:

  void solve (TreeNode* root,  vector<int>&ans){
    if(root==NULL) return ;

    solve(root->left,ans);
    ans.push_back(root->val);
    solve(root->right,ans);
 }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }


    // tc->o(N) , sc->o(N)
    // void solve(TreeNode* root, vector<int>& ans) {
    //     if (root == NULL)
    //         return;

    //     solve(root->left, ans);
    //     ans.push_back(root->val);
    //     solve(root->right, ans);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     solve(root, ans);
    //     return ans;
    // }




    // by using morries traversal tc->o(N) , sc->o(1)

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     TreeNode* curr = root;

    //     while (curr) {
    //         // left node is null , then visit it and go write
    //            // find inorder predecessor
    //             // ek baar left then right right right
    //         if (curr->left == NULL) {
    //             ans.push_back(curr->val);
    //             curr=curr->right;
    //         } else {
    //             TreeNode* pred = curr->left;

    //              while (pred->right != NULL && pred->right != curr) {
    //             pred = pred->right;
    //         }

    //             if (pred->right == NULL) {
    //                 pred->right = curr;
    //                 curr = curr->left;
    //             } else {
    //                 pred->right = NULL;
    //                 ans.push_back(curr->val);
    //                 curr = curr->right;
    //             }
    //         }
    //     }
    //     return ans;
    // }
};
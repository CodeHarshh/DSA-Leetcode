
class Solution {
public:

// ✅ Code Logic Summary (Simple English):
// Start from the root and keep adding node values to the current path.

// Subtract each node’s value from targetSum as you go left or right.

// If you reach a leaf and the remaining sum is 0, save that path.

// After exploring left and right, and once you are returning back, 
// remove the current node from the path to backtrack.

     vector<vector<int>>PathArr;

     void solve(TreeNode* root, int targetSum, vector<int>&curr_path){
      if(!root) return ;
     curr_path.push_back(root->val);

     if(!root->left && !root->right && root->val==targetSum){
        PathArr.push_back(curr_path);
     } 
     
     solve(root->left,targetSum-root->val,curr_path);
     solve(root->right,targetSum-root->val,curr_path);
     
     curr_path.pop_back();
     }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr_path;
        solve(root, targetSum, curr_path);

        return PathArr;
    }


    // vector<vector<int>> ans;

    // void solve(TreeNode* root, int targetSum, vector<int>& curr_path) {
    //     if (root == NULL) return;

    //     curr_path.push_back(root->val);

    //     if (!root->left && !root->right) {
    //         if (targetSum == root->val)
    //             ans.push_back(curr_path);
    //     }

    //     solve(root->left, targetSum - (root->val), curr_path);
    //     solve(root->right, targetSum - (root->val), curr_path);

    //     curr_path.pop_back();
    // }

    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     vector<int> curr_path;
    //     solve(root, targetSum, curr_path);

    //     return ans;
    // }
};
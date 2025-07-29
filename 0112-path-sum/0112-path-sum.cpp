
class Solution {
public:

// Start from the root and subtract each node’s value from the target sum.

// Keep going left and right until you reach a leaf node.

// If at a leaf, the remaining sum equals the node’s value → path found.

// Return true if any such path exists.


  bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return NULL;

        if (!root->left && !root->right) {
           return root->val == targetSum;
        }

        int left = hasPathSum(root ->left, targetSum - root->val);
        int right = hasPathSum(root->right, targetSum - root->val);

        return left || right;
    }
  

    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root==NULL) return false;

    //     if(!root->right && !root->left) {
    //         return targetSum==root->val;
    //     }

    //      bool left_sum=hasPathSum(root->left,targetSum - root->val);
    //      bool right_sum=hasPathSum(root->right,targetSum - root->val);

    //      return left_sum||right_sum;

    // }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }

    bool solve(TreeNode* root, int targetSum, int sum) {
        if(root==NULL) return false;

        sum=sum+root->val;


        bool l = solve(root->left, targetSum, sum );
        bool r = solve(root->right, targetSum, sum );

        if (l == NULL && r == NULL && sum == targetSum)return true;
        if (l == true && r == false)return true;
        if (l == false && r == true)return true;

        return l || r;
    }
};
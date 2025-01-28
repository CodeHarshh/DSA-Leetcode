class NodeValue {
public:
    int minval, maxval, sum;
    bool isBST;
    NodeValue(int minval, int maxval, int sum, bool isBST) {
        this->minval = minval;
        this->maxval = maxval;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution {
public:
    int maxSum = 0;

    NodeValue helper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        NodeValue left = helper(root->left);
        NodeValue right = helper(root->right);

        if (left.isBST && right.isBST && left.maxval < root->val && root->val < right.minval) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return NodeValue(min(root->val, left.minval), max(root->val, right.maxval), currSum, true);
        }

        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
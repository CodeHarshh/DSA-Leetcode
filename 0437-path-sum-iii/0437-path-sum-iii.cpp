class Solution {
public:
 int ans=0;

    void PathfromRoot(TreeNode* root , long long k){
    if(!root) return;
    if(k==root->val) ans++;
     PathfromRoot(root->left,k- (root->val));
     PathfromRoot(root->right,k- (root->val));
    }

    int pathSum(TreeNode* root, int targetSum) {
        PathfromRoot(root,(long long)targetSum);
        if(!root) return 0;
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};
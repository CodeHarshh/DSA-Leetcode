
class Solution {
public:
int maxi=INT_MAX;
int height(TreeNode* root){
    if(root==0)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
      int leftPart=diameterOfBinaryTree(root->left);
      int rightPart=diameterOfBinaryTree(root->right);
      int d=height(root->left)+height(root->right);
    
       return max(d,max(leftPart,rightPart));
    }
};
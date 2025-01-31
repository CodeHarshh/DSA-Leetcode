
class Solution {
public:
    TreeNode*  solve(int &i,vector<int>& preorder,int min_range,int max_range){
        if(i>=preorder.size()) return NULL;                                                          

        TreeNode* root=nullptr;
        if(preorder[i]>min_range && preorder[i]<max_range){
            root=new TreeNode(preorder[i++]);
            root->left=solve(i,preorder,min_range,root->val);
            root->right=solve(i,preorder,root->val,max_range);
        }

      return root;
      }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
          int i=0;
          return solve(i,preorder,INT_MIN,INT_MAX);
    }
};
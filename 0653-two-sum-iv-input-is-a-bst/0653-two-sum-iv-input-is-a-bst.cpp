
class Solution {
public:

    void inorder(vector<int>& v, TreeNode* root) {
       if(!root) return;
       inorder(v,root->left);
       v.push_back(root->val);
       inorder(v,root->right);
    }

    bool findTarget(TreeNode* root, int k) {
       vector<int>v;
       inorder(v,root);
       int i=0,j=v.size()-1;
       while(i<j){
        if(v[i]+v[j]==k)return true;
        else if(v[i]+v[j]>k)j--;
        else if(v[i]+v[j]<k)i++;
       }
       return false;
    }

    // void inorder(vector<int>& v, TreeNode* root) {
    //     if (!root)  return;
    //     inorder(v, root ->left);
    //     v.push_back(root->val);
    //     inorder(v, root->right);
    // }

    // bool findTarget(TreeNode* root, int k) {
    //     vector<int> v;
    //     inorder(v, root);
    //     int i = 0, j = v.size()-1;
    //     while (i < j) {
    //         if (v[i] + v[j] == k) return true;
    //         else if (v[i] + v[j] < k) i++;
    //         else if (v[i] + v[j] > k) j--;
    //     }
    //     return false;
    // }
};

class Solution {
public:
    // M1
    // Tc : O(N) , Sc : O(N)
    // void solve(TreeNode* root,vector<int>&v){
    // if(! root) return;
    //  solve(root->left,v);
    //  v.push_back(root->val);
    //  solve(root->right,v);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int>v;
    //     solve(root,v);
    //     return v[k-1];
    // }

    //M2
    void solve(TreeNode* root,int &cnt,int k,int &ans){
    if(! root) return;
     solve(root->left,cnt,k,ans);
     cnt=cnt+1;
     if(cnt==k){
        ans=root->val;
         return;
        }
     solve(root->right,cnt,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int  ans=-1,cnt=0;
        solve(root,cnt,k,ans);
        return ans;
    }


};
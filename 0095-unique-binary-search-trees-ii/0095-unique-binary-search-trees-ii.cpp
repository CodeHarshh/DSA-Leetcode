
class Solution {
public:


 vector<TreeNode*> solve(int start,int end){

    if(start>end) return {nullptr};


    vector<TreeNode*>ans;

for(int i=start;i<=end;i++){
    vector<TreeNode*>left=solve(start,i-1);
    vector<TreeNode*>right=solve(i+1,end); 

    for(int j=0;j<left.size();j++){
        for(int k=0;k<right.size();k++){
        TreeNode* root=new TreeNode(i);
        root->left=left[j];
        root->right=right[k];
        ans.push_back(root);
        }
    }
}
return ans;
}
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return solve(1,n);
    }
};
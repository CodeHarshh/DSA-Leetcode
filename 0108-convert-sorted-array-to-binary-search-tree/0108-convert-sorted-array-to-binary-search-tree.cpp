
class Solution {
public:
    TreeNode* solve(vector<int>& nums,int n,int s,int e){
        if(s>e)return NULL;
        int mid=(s+e)/2;
        int element =nums[mid];

        TreeNode* root=new TreeNode(element);

        root->left=solve(nums,n,s,mid-1);
        root->right=solve(nums,n,mid+1,e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n=nums.size();
    int s=0;
    int e=n-1;
    TreeNode* root =solve(nums,n,s,e);
    return root;
     
    }
};
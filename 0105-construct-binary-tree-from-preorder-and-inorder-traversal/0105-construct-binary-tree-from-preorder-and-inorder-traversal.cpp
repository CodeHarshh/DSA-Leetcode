
class Solution {
public:
// solution 2
    int preInd = 0;
    void mapping(vector<int>& inorder,unordered_map<int,int>&m){
        for (int i=0;i< inorder.size();i++){
            m[inorder[i]]=i;
        }
    }
    
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int start,
                         int end,unordered_map<int,int>&m) {
        if (start > end) return NULL;

        TreeNode* node = new TreeNode(preorder[preInd++]);
        int pos=m[node->val];
        
        node->left = createTree(preorder, inorder, start, pos - 1,m);
        node->right = createTree(preorder, inorder, pos + 1, end,m);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        mapping(inorder,m);
        return createTree(preorder, inorder, 0, inorder.size() - 1,m);
    }
};
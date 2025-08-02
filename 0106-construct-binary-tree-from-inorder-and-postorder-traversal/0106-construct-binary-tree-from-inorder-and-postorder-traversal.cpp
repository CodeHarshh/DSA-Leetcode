
class Solution {
public:

 
    
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder, int start,
                         int end, unordered_map<int, int>& m, int &postIndx) {
      
      if(start>end) return NULL;
     
     TreeNode* node=new TreeNode(postorder[postIndx--]);
     int pos=m[node->val];
     node->right=createTree(inorder,postorder,pos+1,end,m,postIndx); // right then -> left
     node->left=createTree(inorder,postorder,start,pos-1,m,postIndx);
     
     return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       unordered_map<int,int>m;
       int n=inorder.size()-1;
       int postIndx=n;
       
       for(int i=0;i<=n;i++){ // mapping  inorder element to its indx
        m[inorder[i]]=i;
       }
    return createTree(inorder,postorder,0,n,m,postIndx);
    }




    // void mapping(vector<int>& inorder, unordered_map<int, int>& m) {
    //     for (int i = 0; i < inorder.size(); i++) {
    //         m[inorder[i]] = i;
    //     }
    // }

    // TreeNode* createTree(vector<int>& postorder, vector<int>& inorder, int start,
    //                      int end, unordered_map<int, int>& m, int &postInd) {
    //     if (start > end)
    //         return NULL;
    //     TreeNode* node = new TreeNode (postorder[postInd--]);
    //     int pos = m[node->val];
    //     node->left = createTree(postorder, inorder, start, pos - 1, m,postInd);
    //     node->right = createTree(postorder, inorder, pos + 1, end, m,postInd);
    //     return node;
    // }

    // TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    //     unordered_map<int, int> m;
    //     mapping(inorder, m);
    //     int postInd = postorder.size() -1;
    //     return createTree(postorder, inorder, 0, inorder.size() - 1, m, postInd);
    // }
};

class Solution {
public:
    // only two nodes are swapped by mistake

    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode*& root) {
        if(!root)return;

        inorder(root->left);
        if(prev!=NULL && prev->val > root->val){
            if(first==NULL){ // 1 st time violation;
             first=prev;
             middle=root;
            }
            else{
                last=root;
            } 
        }
         prev=root;
        inorder(root->right);
        
    }

    void recoverTree(TreeNode* root) {
         prev=first=middle=last=NULL;
         inorder(root);
         if(first!=NULL && last!=NULL){
            swap(first->val,last->val);
         }
         else if(first!=NULL && middle!=NULL){
            swap(first->val,middle->val);
         }     

      return;
    }


    // TreeNode* prev;
    // TreeNode* first;
    // TreeNode* middle;
    // TreeNode* last;

    // void inorder(TreeNode*& root) {
    //     if (!root)return;
    //     inorder(root->left);

    //     if (prev != NULL && (root->val < prev->val)) { //  voilation occurs
    //         if (first == NULL) {                       // first time voilation
    //             first = prev;
    //             middle = root;
    //         } else { // second time voilation
    //             last = root;
    //         }
    //     }
    //     prev = root;
    //     inorder(root->right);
    // }

    // void recoverTree(TreeNode* root) {
    //     first = middle = last = NULL;
    //     prev = new TreeNode(INT_MIN);
    //     inorder(root);
    //     if (first && last) // if 2 time voilation occur
    //         swap(first->val, last->val);
    //     else if (first && middle) // if only  one time violation occurs
    //         swap(first->val, middle->val);
    // }
};
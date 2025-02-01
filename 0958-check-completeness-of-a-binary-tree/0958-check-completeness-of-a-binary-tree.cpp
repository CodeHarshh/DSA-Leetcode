
class Solution {
public:
    // see numbering
    bool issolve(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);

       bool nullFound=false;

       while(!q.empty()){
       TreeNode* front=q.front();
       q.pop();

       if(front==NULL){
        nullFound=true;
       }
       else{
        if(nullFound==true) return false;
        else  {q.push(front->left); q.push(front->right);}
       }
       }
       return true;
    }

    bool isCompleteTree(TreeNode* root) {
        bool ans = issolve(root);
        return ans;
    }
};

class Solution {
public:
 // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> ans;

    //     if (root == NULL) return ans;
    //     queue<TreeNode*> q;
    //     q.push(root);

    //     while (!q.empty()) {
    //         int size = q.size();

    //         vector<int> arr;

    //         for (int i = 0; i < size; i++) {
    //             TreeNode* front = q.front();
    //             q.pop();

    //             arr.push_back(front->val);

    //             if (front->left != NULL) {
    //                 q.push(front->left);
    //             }
    //             if (front->right != NULL) {
    //                 q.push(front->right);
    //             }
    //         }
    //         ans.push_back(arr);
    //     }
    //     return ans;
// }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>arr;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                arr.push_back(front->val);
                if(front->left)  q.push(front->left);
                if(front->right)  q.push(front->right);

            }
        ans.push_back(arr);

        }
        return ans;
    }
};
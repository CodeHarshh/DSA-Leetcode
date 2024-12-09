
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (!root)  return ans;
        q.push(root);
        bool leftToRight = false;

        while (!q.empty()) {
            int size = q.size();
            vector<int> lvlAns;

            for (int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                lvlAns.push_back(it->val);
                
                if (it->right != NULL) q.push(it->right);
                if (it->left != NULL) q.push(it->left);
            }

            if (!leftToRight) reverse(lvlAns.begin(), lvlAns.end());
            ans.push_back(lvlAns);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
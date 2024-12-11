// row , column mein left gye to c-1 and right gye to c+1 and r always r+1
//(r,c) ->left (r+1,c-1)
//(r,c) ->right (r+1,c+1)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q; // (node,(r,c))
        map<int, map<int, multiset<int>>> m;

        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto front = q.front(); q.pop();
            auto node = front.first;

            int row = front.second.first;
            int col = front.second.second;

            m[col][row].insert(node->val);

            if (node->left) q.push({node->left, {row + 1, col - 1}});
            
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }
            // final store
            for (auto it : m) {
                auto p = it.second;
                vector<int> rizz;
                for (auto q : p) {
                   rizz.insert(rizz.end(), q.second.begin(), q.second.end());
                }
                ans.push_back(rizz);
        }
         return ans;
    }
};
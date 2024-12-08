
class Solution {
public:
    void mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m) {
        if (!root)return;
        if (root->left) {
            m[root->left] = root;
            mapping(root->left, m);
        }
        if (root->right) {
            m[root->right] = root;
            mapping(root->right, m);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        // it will maker visited node
        unordered_map<TreeNode*, bool> visited;
        mapping(root, m);
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int current_lvl = 0;

        while (!q.empty() ) {
            int size = q.size();
            if(current_lvl == k) break;
            current_lvl++;

            for (int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();

                if (front->left && visited.find(front->left) == visited.end()) {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right &&
                    visited.find(front->right) == visited.end()) {
                    q.push(front->right);
                    visited[front->right] = true;
                }

               if(m[front]&& visited.find(m[front])==visited.end()){
            q.push(m[front]);
            visited[m[front]]=true;
               }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back(it->val);
        }
        return ans;
    }
};
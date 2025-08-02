
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

         unsigned long long  maxwidth = 0;
        if (!root)return maxwidth;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        while (!q.empty()) {
           unsigned long long  size = q.size();
           unsigned   long long  s = q.front().second;
             unsigned long long  e = q.back().second;

            maxwidth = max(maxwidth, e - s + 1);

            for (int i = 0; i < size; i++) {
                auto it = q.front();

                unsigned long long  indx = it.second;
                q.pop();

                if (it.first->left != NULL) {
                    q.push({it.first->left, 2 * indx});
                }
                if (it.first->right != NULL) {
                    q.push({it.first->right, 2 * indx + 1});
                }
            }
        }

        return maxwidth;
    }
};
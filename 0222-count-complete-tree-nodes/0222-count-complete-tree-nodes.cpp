
class Solution {
public:
    void solve(TreeNode* root, int& cnt) {
        if (!root) return;
        cnt++;
        solve(root->left,cnt);
        solve(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);

        return cnt;
    }
};
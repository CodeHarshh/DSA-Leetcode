
class Solution {
public:
    // we can't add camera to the leaf node but sometime it can
    // 0->i am not coverd
    // 1-> i am coverd
    // 2->i have cam

    int solve(TreeNode* root, int& cam) {
        if (!root)return 1;

        int leftside = solve(root->left, cam);
        int rightside = solve(root->right, cam);

        if (leftside == 0 || rightside == 0) {
            cam++;
            return 2;
        }
        if (leftside == 2 || rightside == 2) return 1;

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        int cam = 0;
        if (!root)
            return 0;
        if (solve(root, cam) == 0)
            cam++;

        return cam;
    }
};
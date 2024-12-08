
class Solution {
public:
    // we can't add camera to the leaf node but sometime it can
    // 0->i am not coverd
    // 1-> i am coverd
    // 2->i have cam

    int solve(TreeNode* root, int& cam) {
        if (!root) return 1;

        if (!root->left && !root->right)
            return 1;

        int leftside = solve(root->left, cam);
        int rightside = solve(root->right, cam);

        if (leftside == 1 && rightside == 1) return 0;
        if (leftside == 0 && rightside == 0) {
            cam++;
            return 2;
        }
        if (leftside == 2 && rightside == 2) return 1;

        if (leftside == 2 && rightside == 0) {
           cam++;
            return 2;
        }
        if (leftside == 0 && rightside == 2) {
            cam++;
            return 2;
        }
        if (leftside == 1 && rightside == 0) {
            return 2;
        }
        if (leftside == 0 && rightside == 1) {
            cam++;
            return 2;
        }

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        int cam = 0;
        if (!root)
            return cam;
        solve(root, cam);

        return cam;
    }
};
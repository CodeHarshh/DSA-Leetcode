
class Solution {
public:
    //   ✅ Width of Binary Tree – Summary
    // Use level order traversal (BFS) with a queue storing {node, index}
    // (starting index = 1). For each level, record the first and last indices,
    // then compute: width = last - first + 1. Run a for loop from 0 to size -
    // 1, pop each node, and: Push left child with index 2 * i Push right child
    // with index 2 * i + 1 Always push children at the back of the queue. After
    // each level, update maxWidth if the current width is larger.

    int widthOfBinaryTree(TreeNode* root) {

         unsigned long long maxwidth = 0;
        if (!root)
            return maxwidth;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

             unsigned long long front = q.front().second;
             unsigned long long back = q.back().second;
             unsigned long long width = back - front + 1;

            maxwidth = max(maxwidth, width);
            for (int i = 0; i < size; i++) {
                  auto it = q.front();
                  q.pop();
                  
                  TreeNode* node=it.first;
                   unsigned long long indx=it.second;

                  if(node->left){
                    q.push({node->left,2*indx+1});
                  }

                  if(node->right){
                    q.push({node->right,2*indx+2});
                  }  
            }
  
         }
     return maxwidth;
    }

    

    // int widthOfBinaryTree(TreeNode* root) {

    //      unsigned long long  maxwidth = 0;
    //     if (!root)return maxwidth;

    //     queue<pair<TreeNode*, unsigned long long>> q;
    //     q.push({root, 1});

    //     while (!q.empty()) {
    //        unsigned long long  size = q.size();
    //        unsigned   long long  s = q.front().second;
    //          unsigned long long  e = q.back().second;

    //         maxwidth = max(maxwidth, e - s + 1);

    //         for (int i = 0; i < size; i++) {
    //             auto it = q.front();

    //             unsigned long long  indx = it.second;
    //             q.pop();

    //             if (it.first->left != NULL) {
    //                 q.push({it.first->left, 2 * indx});
    //             }
    //             if (it.first->right != NULL) {
    //                 q.push({it.first->right, 2 * indx + 1});
    //             }
    //         }
    //     }

    //     return maxwidth;
    // }
};
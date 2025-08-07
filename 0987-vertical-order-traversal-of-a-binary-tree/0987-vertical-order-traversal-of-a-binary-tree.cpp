// row , column mein left gye to c-1 and right gye to c+1 and r always r+1
//(r,c) ->left (r+1,c-1)
//(r,c) ->right (r+1,c+1)

class Solution {
public:

// map<   // for sorted columns
//    int, 
//    map<   // for sorted rows inside each column
//        int, 
//        multiset<int>   // for storing multiple values at same (row,col)
//    >
// > m;


    vector<vector<int>> verticalTraversal(TreeNode* root) {

       vector<vector<int>>ans;
       map<int,map<int,multiset<int>>>m;    //// imp
       queue<pair<TreeNode*,pair<int,int>>>q;
       q.push({root,{0,0}});

       while(!q.empty()){
         auto it=q.front();
         q.pop();
         int row=it.second.first;
         int col=it.second.second;

         m[row][col].insert(it.first->val);

         if(it.first->left){
            q.push(  { it.first->left,{row-1,col+1} } );
         }
          if(it.first->right){
            q.push({ it.first->right,{row+1,col+1} });
         }  
         
       }

      for (auto& col : m) {
    vector<int> temp;
    for (auto& row : col.second) {
        for (int val : row.second) {
            temp.push_back(val);
        }
    }
    ans.push_back(temp);
}

  return ans;

    }

    // vector<vector<int>> verticalTraversal(TreeNode* root) {

    //     vector<vector<int>> ans;
    //     queue<pair<TreeNode*, pair<int, int>>> q; // (node,(r,c))
    //     map<int, map<int, multiset<int>>> m;

    //     q.push({root, {0, 0}});
    //     while (!q.empty()) {
    //         auto front = q.front(); q.pop();
    //         auto node = front.first;

    //         int row = front.second.first;
    //         int col = front.second.second;

    //         m[col][row].insert(node->val);

    //         if (node->left) q.push({node->left, {row + 1, col - 1}});
            
    //         if (node->right) q.push({node->right, {row + 1, col + 1}});
    //     }
    //         // final store
    //         for (auto it : m) {
    //             auto p = it.second;
    //             vector<int> rizz;
    //             for (auto q : p) {
    //                rizz.insert(rizz.end(), q.second.begin(), q.second.end());// rizz ke end me q ke start se insert kro till end 
    //             }

    //             ans.push_back(rizz);
    //     }
    //      return ans;
    // }
};
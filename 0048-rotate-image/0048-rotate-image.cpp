class Solution {


    public:
    void rotate(vector<vector<int>>& m) {
    int row=m.size();
    int col=m[0].size();
    
    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++){   // If you start j = 0, you'll swap each pair twice and mess up the matrix.
            swap(m[i][j], m[j][i]);
        }
    }
    for(int i=0;i<row;i++){
        reverse(m[i].begin() ,m[i].end());
    }
    }

























// public:
//     void rotate(vector<vector<int>>& matrix) {

//         int row = matrix.size();
//         int col = matrix[0].size();

//         for (int i = 0; i < row; i++) {
//             for (int j = i; j < col; j++) { // j==i hoga
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

//         for (int i = 0; i < row; i++) {
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
};
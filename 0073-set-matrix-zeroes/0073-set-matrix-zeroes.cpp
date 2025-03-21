
class Solution {
public:

///////// https://www.youtube.com/watch?v=N0MgLvceX7M&t=493s&ab_channel=takeUforward

// m-1 simple but o(N)^3
// Iterate through the matrix to find cells with 0.
// For each 0, mark all cells in its row and column as -10 (if not already 0).
// Iterate through the matrix again, replacing all -10 values with 0.
//void marki(int i,vector<vector<int>>& matrix){
//  for(int j=0;j<matrix[0].size();j++){
//  if(matrix[i][j]!=0){
//   matrix[i][j]=-10;
//         }
//     }

// }
// void markj(int j,vector<vector<int>>& matrix){
//  for(int i=0;i<matrix.size();i++){
//         if(matrix[i][j]!=0){
//             matrix[i][j]=-10;
//         }
//     }
// }
//     void setZeroes(vector<vector<int>>& matrix) {

//      for(int i=0;i<matrix.size();i++){
//         for(int j=0;j<matrix[0].size();j++){
//             if( matrix[i][j]==0){
//                  marki(i,matrix);
//                  markj(j,matrix);
//             }
            
//         }
//      }

//           for(int i=0;i<matrix.size();i++){
//         for(int j=0;j<matrix[0].size();j++){
//          if(matrix[i][j]==-10){
//             matrix[i][j]=0;
//          }
//         }
//           }
//     }








/// m-2 with tc- o(n^2) sc-o(N)
    //   void setZeroes(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //      vector<int>v1(n,-1);
    //      vector<int>v2(m,-1);
    //      for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //         if(matrix[i][j]==0){
    //             v1[i]=0;
    //             v2[j]=0;
    //         }
    //         }
    //      }
    //       for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(v1[i]==0 || v2[j]==0){
    //               matrix[i][j]=0;
    //             }

    //              }
    //      }
    //       }






// m3- most optimal soltion
void setZeroes(vector<vector<int>>& matrix) {
    // instead of taking seprate array for row col we will use the first row and
    // col of the array
    int n = matrix.size();
    int m = matrix[0].size();

    int col0 = 1; // this is the collided box so we take a separate var for col
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if (j != 0) {
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int i = 0; i < m; i++) {
            matrix[0][i] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}
}
;
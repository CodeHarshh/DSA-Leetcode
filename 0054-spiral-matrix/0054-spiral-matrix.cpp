class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;

        int row = m.size();
        int col = m[0].size();
        int total = row * col;

        int startCol = 0 ;
        int endCol = col - 1;

        int startRow = 0;
        int endRow = row - 1;

        int cnt = 0;
        while (cnt < total) {

            for (int i = startCol; i <= endCol && cnt<total ; i++) { // && cnt<total ---> imp
                ans.push_back(m[startRow][i]);
                cnt++;
            }
            startRow++;

            for (int i = startRow; i <= endRow && cnt<total; i++) {
                ans.push_back(m[i][endCol]);
                cnt++;
            }
            endCol--;

            for (int i = endCol; i >= startCol && cnt<total; i--) {
                ans.push_back(m[endRow][i]);
                cnt++;
            }
            endRow--;
      

            for (int i = endRow; i >= startRow && cnt<total; i--) {
                ans.push_back(m[i][startCol]);
                cnt++;
            }
            startCol++;
        }
   return ans;
   }
       
    };









    //     vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //         vector<int>ans;
    //         int m=matrix.size();
    //         int n=matrix[0].size();
    //         int total=m*n;

    //     int StartingColumn=0;
    //     int EndingColumn=n-1;
    //        int EndingRow=m-1;
    //     int StartingRow=0;

    // int cnt=0;

    // while(cnt<total){

    // for(int i=StartingColumn;i<=EndingColumn  && cnt<total;i++){
    //     ans.push_back(matrix[StartingRow][i]);
    // cnt++;

    // }
    // StartingRow++;

    // for(int i=StartingRow;i<=EndingRow  && cnt<total;i++){
    //      ans.push_back(matrix[i][EndingColumn]);
    //  cnt++;
    // }
    // EndingColumn--;

    // for(int i=EndingColumn;i>=StartingColumn  && cnt<total;i--){
    //      ans.push_back(matrix[EndingRow][i]);
    //   cnt++;
    // }
    // EndingRow--;

    // for(int i=EndingRow;i>=StartingRow  && cnt<total ;i--){
    //      ans.push_back(matrix[i][StartingColumn]);
    //  cnt++;
    // }
    // StartingColumn++;

    //     }
    // return ans;
    //     }
// };
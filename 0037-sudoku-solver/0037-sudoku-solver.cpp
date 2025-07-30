class Solution {
public:
    //*******

    bool issafe(vector<vector<char>>& board, char digit, int row, int col) {
      int n=board.size();
     
     for(int i=0;i<n;i++){  // row check
      if(board[row][i]==digit) return false; 
     }

     for(int i=0;i<n;i++){  // row check
      if(board[i][col]==digit) return false; 
     }
     
     // grid check
     int colst=(col/3)*3;  // starting col indx of the  curr i,j grid 
     int rowst=(row/3)*3;  // starting row indx of curr i,j grid 
     
     for(int i=rowst;i<=rowst+2;i++){
        for(int j=colst;j<=colst+2;j++){
              if(board[i][j]==digit) return false; 
        }
     }
    return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){

                     for(char digit ='1';digit <='9';digit++){
                      if(issafe(board,digit,i,j)){
                           board[i][j] = digit;
                           bool reccAns =solve(board);

                          if (reccAns) return true;

                            // Backtrack
                            board[i][j] = '.';
                      }
                     }
                     return false;
                    
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { 
        solve(board); 
     }



    // bool issafe(vector<vector<char>>& board, char digit, int row, int col) {
    //     // rowcheck
    //     int n = board.size();
    //     for (int i = 0; i < n; i++) {
    //         if (board[row][i] == digit) {
    //             return false;
    //         }
    //     }
    //     // colcheck
    //     for (int i = 0; i < n; i++) {
    //         if (board[i][col] == digit) {
    //             return false;
    //         }
    //     }
    //     // 3x3 wali matrix check
    //     int stRow =row/3*3 ;
    //     int stCol=col/3* 3;
          
    //       for(int i=stRow;i<=stRow+2;i++){
    //         for(int j=stCol;j<=stCol+2;j++){
    //             if(board[i][j]==digit) return false;
    //         }
    //       }
    //     return true;
    // }

    // bool solve(vector<vector<char>>& board) {
    //     // base case ->?
    //     // base case not needed
    //     // Ek case hm karenge

    //     // first find the empty cell -> '.'
    //     for (int i = 0; i < board.size(); i++) {
    //         for (int j = 0; j < board.size(); j++) {
    //             if (board[i][j] == '.') {
    //                 for (char digit = '1'; digit <= '9'; digit++) {

    //                     if (issafe(board, digit, i, j)) {
    //                         board[i][j] = digit;
    //                         bool agyeSolvehopayega = solve(board);
    //                         if (agyeSolvehopayega) {
    //                             return true;
    //                         } else {
    //                             board[i][j] = '.';
    //                         }
    //                     }
    //                 }

    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    // void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
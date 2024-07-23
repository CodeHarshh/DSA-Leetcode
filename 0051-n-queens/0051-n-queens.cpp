class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> UpperdigonalCheck;
    unordered_map<int, bool> lowerDigonalCheck;

    void storeSoln(vector<vector<char>>& board, vector<vector<string>>& ans,
                   int n) {
        vector<string> tempans;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            tempans.push_back(output);
        }
        ans.push_back(tempans);
        return;
    }

    bool issafe(vector<vector<char>>& board, int row, int col) {
        // check for upperdiagonal
        if (UpperdigonalCheck[row + col] == true) {
            return false;
        }
        // check for row
        if (rowCheck[row] == true) {
            return false;
        }
        // check for lowwerdiagonal
        if (lowerDigonalCheck[row - col] == true) {
            return false;
        }
        return true;
    }

    void solve(int n, vector<vector<char>>& board, vector<vector<string>>& ans,
               int col) {
        // base case
        if (col >= n) {
            // all queens are placed & now store the ans
            storeSoln(board, ans, n);
        }
        // 1 case hm karenge
        for (int row = 0; row < n; row++) {
            if (issafe(board, row, col)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                UpperdigonalCheck[row + col] = true;
                lowerDigonalCheck[row - col] = true;

                solve(n, board, ans, col + 1);
                // now we backTrack ->
                board[row][col] = '.';
                rowCheck[row] = false;
                UpperdigonalCheck[row + col] = false;
                lowerDigonalCheck[row - col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        solve(n, board, ans, col);
        return ans;
    }
};
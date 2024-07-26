class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int row, int col,
               int indx) {
        if (indx == word.size())
            return true;
        if (row < 0 || row >= board.size())
            return false;
        if (col < 0 || col >= board[0].size())
            return false;
        if (board[row][col] != word[indx])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';
        // up down left right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newx = row + dx[i];
            int newy = col + dy[i];
            if (solve(board, word, newx, newy, indx + 1)) {
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {        // rows
            for (int j = 0; j < board[0].size(); j++) { // col
                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
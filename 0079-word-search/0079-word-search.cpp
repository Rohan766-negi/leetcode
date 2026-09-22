class Solution {
public:
    void solve(vector<vector<char>>& board, string &word, bool &x,
               int row, int col, int idx, vector<vector<int>>& visited) {

        if(board[row][col] != word[idx]) {
            return;
        }

        visited[row][col] = 1;

        if(idx == word.length() - 1) {
            x = true;
            visited[row][col] = 0;
            return;
        }

        int newrow = row;
        int newcol = col + 1;

        if(newrow >= 0 && newrow < board.size() &&
           newcol >= 0 && newcol < board[0].size() &&
           visited[newrow][newcol] == 0) {

            solve(board, word, x, newrow, newcol, idx + 1, visited);
        }

        newrow = row;
        newcol = col - 1;

        if(newrow >= 0 && newrow < board.size() &&
           newcol >= 0 && newcol < board[0].size() &&
           visited[newrow][newcol] == 0) {

            solve(board, word, x, newrow, newcol, idx + 1, visited);
        }

        newrow = row + 1;
        newcol = col;

        if(newrow >= 0 && newrow < board.size() &&
           newcol >= 0 && newcol < board[0].size() &&
           visited[newrow][newcol] == 0) {

            solve(board, word, x, newrow, newcol, idx + 1, visited);
        }

        newrow = row - 1;
        newcol = col;

        if(newrow >= 0 && newrow < board.size() &&
           newcol >= 0 && newcol < board[0].size() &&
           visited[newrow][newcol] == 0) {

            solve(board, word, x, newrow, newcol, idx + 1, visited);
        }

        visited[row][col] = 0;
    }

    bool exist(vector<vector<char>>& board, string word) {

        bool x = false;

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                solve(board, word, x, i, j, 0, visited);
            }
        }

        return x;
    }
};
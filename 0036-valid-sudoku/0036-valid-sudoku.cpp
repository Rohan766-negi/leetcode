class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        map<pair<int, int>, int> mp;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {

                if (board[i][j] != '.') {

                    int num = board[i][j] - '0';

                    if (mp[{i, num}]++) {
                        return false;
                    }

                    if (mp[{j + 9, num}]++) {
                        return false;
                    }

                    int box = (i / 3) * 3 + (j / 3);

                    if (mp[{box + 18, num}]++) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
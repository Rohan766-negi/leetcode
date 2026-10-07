class Solution {

public:
    void solve(vector<vector<int>>& ans, int i, int j, int color, int old) {
        ans[i][j] = color;

        if (i > 0 && ans[i - 1][j] == old) {
            solve(ans, i - 1, j, color, old);
        }

        if (i < ans.size() - 1 && ans[i + 1][j] == old) {
            solve(ans, i + 1, j, color, old);
        }

        if (j > 0 && ans[i][j - 1] == old) {
            solve(ans, i, j - 1, color, old);
        }

        if (j < ans[0].size() - 1 && ans[i][j + 1] == old) {
            solve(ans, i, j + 1, color, old);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int old = image[sr][sc];

        if (old == color) {
            return ans;
        }

        solve(ans, sr, sc, color, old);

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        int c = 1;
        int step = 1;

        vector<vector<int>> ans;

        ans.push_back({rStart, cStart});

        while (c < rows * cols) {

            for (int i = 0; i < step; i++) {
                cStart++;

                if (rStart >= 0 && rStart < rows &&
                    cStart >= 0 && cStart < cols) {
                    ans.push_back({rStart, cStart});
                    c++;
                }
            }

            for (int i = 0; i < step; i++) {
                rStart++;

                if (rStart >= 0 && rStart < rows &&
                    cStart >= 0 && cStart < cols) {
                    ans.push_back({rStart, cStart});
                    c++;
                }
            }

            step++;

            for (int i = 0; i < step; i++) {
                cStart--;

                if (rStart >= 0 && rStart < rows &&
                    cStart >= 0 && cStart < cols) {
                    ans.push_back({rStart, cStart});
                    c++;
                }
            }

            for (int i = 0; i < step; i++) {
                rStart--;

                if (rStart >= 0 && rStart < rows &&
                    cStart >= 0 && cStart < cols) {
                    ans.push_back({rStart, cStart});
                    c++;
                }
            }

            step++;
        }

        return ans;
    }
};
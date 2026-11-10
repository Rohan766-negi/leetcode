class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<int>ans(2);
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));

        int i = 0;
        int j = 0;
        while (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
               visited[i][j] == false) {
            visited[i][j] = true;
             ans[0] = i;
            ans[1] = j;
            if (grid[i][j] == 'L') {
                j--;
            } else if (grid[i][j] == 'R') {
                j++;
            } else if (grid[i][j] == 'U') {
                i--;
            } else {
                i++;
            }

           
        }
   return ans;
    }
    
};
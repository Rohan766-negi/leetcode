class Solution {
public:
     void addsol(vector<string>& b, vector<vector<string>>& ans, int n) {
        ans.push_back(b);
    }
    bool issafe(int row,int col,vector<string>&b,int n){
          for(int j = 0; j < col; j++) {
            if(b[row][j] == 'Q') {
                return false;
            }

            }
            int i=row;
            int j=col;
            while(i<n&&j>=0){
                if(b[i][j]=='Q'){
                    return false;
                }
                i++;
                j--;
            }
             i=row;
             j=col;
            while(j>=0&&i>=0){
                if(b[i][j]=='Q'){
                    return false;
                }
                i--;
                j--;
            }
            return true;

        }
    

    void solve(int col, vector<string>&b, int n,vector<vector<string>>&ans) {
        if (col == n) {
            addsol(b,ans,n);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (issafe(i, col, b,n)) {
                b[i][col] = 'Q';
                solve(col + 1, b, n,ans);
                b[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> b(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, b, n, ans);
        return ans;
    }
};
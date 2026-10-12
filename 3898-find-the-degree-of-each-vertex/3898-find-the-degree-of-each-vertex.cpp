class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans;
        for( int i=0; i<matrix.size(); i++){
            int x=0;
            for( int j=0; j<matrix[i].size(); j++){
                 x+=matrix[i][j];
            }
            ans.push_back(x);
        }
        return ans;
    }
};
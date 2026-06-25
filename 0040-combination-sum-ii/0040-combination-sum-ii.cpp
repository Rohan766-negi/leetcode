class Solution {
    void solve(vector<vector<int>>& ans, vector<int>& candidates, int target,
               int idx, vector<int> output, int sum) {
        if (sum > target)
            return;
        if (sum == target) {
            ans.push_back(output);
            return;
        }
        if (idx == candidates.size()) {
            return;
        }

        sum = sum + candidates[idx];
        output.push_back(candidates[idx]);
        solve(ans, candidates, target, idx + 1, output, sum);
        output.pop_back();
        sum = sum - candidates[idx];
        while (idx < candidates.size()-1 &&
               candidates[idx] == candidates[idx + 1])
            idx++;
        solve(ans, candidates, target, idx + 1, output, sum);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int idx = 0;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        solve(ans, candidates, target, idx, output, sum);

        return ans;
    }
};
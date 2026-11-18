class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans[j] = 0;
                j++;
            }
        }
        return ans;
    }
};
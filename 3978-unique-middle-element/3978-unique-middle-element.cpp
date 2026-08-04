class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums[nums.size() / 2];
        nums[nums.size() / 2]=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == n) {
                return false;
            }
        }
        return true;
    }
};
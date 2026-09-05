class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       
        int n = nums.size();
        vector<int> mini(n);
        int minval = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            minval = min(minval, nums[i]);
            mini[i] = minval;
        }
        int max = nums[0];
        for (int i = 0; i < n; i++) {
            if (max < nums[i]) {
                max = nums[i];
            }

            if ((max - mini[i]) <= k) {
                return i;
            }
        }

        return -1;
    }
};
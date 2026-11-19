class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];

            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }

        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, total - minSum);
    }
};
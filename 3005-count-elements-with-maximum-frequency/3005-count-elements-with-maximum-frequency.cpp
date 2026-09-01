class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxfre = 0;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            maxfre = max(maxfre, count[nums[i]]);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] == maxfre) {
                ans += maxfre;
            }
        }
        return ans/maxfre;
    }
};
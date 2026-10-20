class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        int x;
        vector<int> ret(2);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[nums[i]]++;

            if (mp[nums[i]] > 1) {
                x = nums[i];
            }
        }
        sum -= x;
        int ans = (n * (n + 1) / 2) - sum;
        ret[0] = x;
        ret[1] = ans;

        return ret;
    }
};
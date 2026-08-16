class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int i = 0;
        int j = 0;
        int bits = 0;

        int ans = 0;
        while (j < nums.size()) {
            if ((bits & nums[j]) == 0) {
                bits = nums[j] | bits;
                j++;
            }
            else{
              bits = bits ^ nums[i];
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
         int maximum = 0;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            maximum = max(maximum,nums[i]);
            sum = sum + nums[i];
        }
        return (n*maximum)-sum;
    }
};
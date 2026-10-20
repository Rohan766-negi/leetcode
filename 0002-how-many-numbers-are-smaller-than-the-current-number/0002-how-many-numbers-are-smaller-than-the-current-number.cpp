class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans = nums;

        sort(ans.begin(), ans.end());
        vector<int> array(ans[ans.size()-1] + 1, -1);
      


        for( int i=0; i<ans.size(); i++){
            if (array[ans[i]] == -1) {
                array[ans[i]] = i;
            }
        }
        for( int i=0; i<nums.size(); i++){
            ans[i] = array[nums[i]];
        }
        return ans;
    }
};
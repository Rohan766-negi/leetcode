class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for( int i=0; i<nums.size(); i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }

        if( maxi==mini){
            return 0;
        }
        mini+=k;
        if(maxi-mini<k){
            return 0;
        }
        maxi-=k;
        return maxi-mini;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int maxind=0;
        for(int i=0; i<n && i<=maxind; i++){
            maxind= max((nums[i]+i), maxind);
            
           
        }

        return maxind>=n-1? true:false;
    }
};
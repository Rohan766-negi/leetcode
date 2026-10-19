class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       vector<int>ans;
       int x=0;
       int y=0;
       for( int i=0; i<nums.size(); i++){
        if( nums[i]==target){
            x++;
        }
        else if(nums[i]<target){
            y++;
        }

       } 
       x+=y;
       for( int i=y; y<x; y++){
        ans.push_back(y);
       }
       return ans;
    }
};
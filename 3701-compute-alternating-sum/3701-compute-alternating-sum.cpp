class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int x=0;
        int y=0;

        for( int i=0; i<nums.size(); i++){
            if(i%2==0){
                x+=nums[i];
            }
            else{
                y+=nums[i];
            }
        }
        return x-y;
    }
};
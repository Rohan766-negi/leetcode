class Solution {
public:
    int minMoves(vector<int>& nums) {
       int sum=0;
       int n=nums.size();
       int mini=INT_MAX;

       for( int i=0; i<n; i++){
        sum+=nums[i];
        mini=min(mini,nums[i]);
       }

       
        return sum-(n*mini) ;

        
    }
};
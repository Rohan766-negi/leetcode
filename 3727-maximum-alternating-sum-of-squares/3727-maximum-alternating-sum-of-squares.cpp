class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for( int i=0; i<nums.size(); i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
         int j=nums.size()-1;
         int i=0;
         long long ans=0;
         while(i<=j){
            if(i==j){
                ans=ans+nums[j];
           
            }else{
           ans=ans+nums[j]-nums[i];
           
            }
            i++;
           j--;
         }
         return ans;
    }
};
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int i=0;
        int j=1;
        int ans=0;
        while(j<nums.size()){
             bool good=true;
           
           for(int k=i; k<j; k++){
            if((nums[k]&nums[j])!=0){
                 good=false;
                 break;
            }

           }
            
             if(good) {
                j++;
                ans = max(ans, j - i);
            }
            else {
                i++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
          int mini=INT_MAX;
          int maxi=INT_MIN;
          map<int,int>mp;

        for( int i=0; i<nums.size(); i++){
            mini=min(mini,nums[i]);
             maxi=max(maxi,nums[i]);
             mp[nums[i]]++;
        }
        
        for( int i=mini; i<=maxi; i++){
            if(mp[i]!=1)
            ans.push_back(i);
        }

        return ans;

           
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int maxi = 0;

        for(int i = 0; i < nums.size(); i++){

            if(mp[nums[i]] == 0){
                continue;
            }

            if(mp[nums[i] - 1] == 0){
                int x = 0;
                int y = nums[i];

                while(mp[y] != 0){
                    x++;
                    mp[y] = 0;
                    y++;
                }

                maxi = max(maxi, x);
            }
        }

        return maxi;
    }
};
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for( int i=0; i<edges.size(); i++){
               for(auto nei:edges[i]){
                mp[nei]++;
               }
        }
    int ans=0;
        for( auto a:mp){
            if(a.second>1){
                return a.first;
            }
        }

        return ans;
    }
};
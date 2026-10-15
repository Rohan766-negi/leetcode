class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        int m = friends.size();
        vector<int> ans;
        unordered_map<int,int> f;

        
        for(int i = 0 ; i<m; i++){
            f[friends[i]]++;
        }
        for(int i = 0; i<n; i++){
          if(f[order[i]] > 0){
            ans.push_back(order[i]);
          }
        }

        return ans;
    }
};
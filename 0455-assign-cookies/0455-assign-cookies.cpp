class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        for(int i=0; i<s.size(); i++){
            if(ans<g.size()&&g[ans]<=s[i]){
                ans++;
            }
        }
        return ans;
    }
};
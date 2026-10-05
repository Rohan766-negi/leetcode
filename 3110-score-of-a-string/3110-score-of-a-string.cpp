class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;

        for( int i=1; i<s.length(); i++){
         ans+=abs((s[i-1]-'0')-(s[i]-'0'));
        }
        return ans;
    }
};
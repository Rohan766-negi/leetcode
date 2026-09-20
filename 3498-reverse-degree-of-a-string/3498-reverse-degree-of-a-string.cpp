class Solution {
public:
    int reverseDegree(string s) {
    int ans=0;
        for( int i=0; i<s.length(); i++){
           int x=(26-(s[i]-'a'));
           x=x*(i+1);
           ans=ans+x;

        }
        return ans;
    }
};
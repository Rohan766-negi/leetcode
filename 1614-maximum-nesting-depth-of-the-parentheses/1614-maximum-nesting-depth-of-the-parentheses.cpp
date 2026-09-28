class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;

        int mx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                mx++;
            } else if (s[i] == ')') {
                ans = max(mx, ans);
                mx--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool checkString(string s) {
        bool x = false;
        for (int i = s.length() - 1; i >= 0;  i--) {
            if (s[i] == 'a') {
                x = true;
            }
            if (x && s[i] == 'b') {
                return false;
            }
        }
        return true;
    }
};
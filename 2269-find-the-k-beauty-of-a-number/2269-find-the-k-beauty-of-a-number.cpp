class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;

        int x = 0;
        for (int i = 0; i < k; i++) {
            x = (x * 10) + (s[i] - '0');
        }

        if (num % x == 0) {
            ans++;
        }
        int i = k;

        for (int i = k; i < s.size(); i++) {
            x = x - (s[i - k] - '0') * pow(10, k - 1);
            x = x * 10 + (s[i] - '0');

            if (x != 0 && num % x == 0) {
                ans++;
            }
        }
        k++;
        return ans;
    }
}

;
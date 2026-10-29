
class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            if (word[i] == 'a' || word[i] == 'e' ||
                word[i] == 'i' || word[i] == 'o' ||
                word[i] == 'u') {
                
                ans += (long long)(i + 1) * (n - i);
            }
        }

        return ans;
    }
};

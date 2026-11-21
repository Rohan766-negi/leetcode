class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans[26] = {0};

        for (int i = 0; i < allowed.length(); i++) {
            ans[allowed[i] - 'a']++;
        }

        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            bool flag = true;

            for (int j = 0; j < words[i].length(); j++) {
                if (ans[words[i][j] - 'a'] == 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                count++;
            }
        }

        return count;
    }
};
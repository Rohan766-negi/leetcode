class Solution {
public:
    string minWindow(string s, string t) {
         if (s.size() < t.size()) {
            return "";
        }

        map<char, int> mp;

        for (int k = 0; k < t.size(); k++) {
            mp[t[k]]++;
        }

        int i = 0;
        int j = 0;

        int ansi = -1;
        int ansj = -1;
        int count = t.size();
        int minLen = INT_MAX;

        while (j < s.size()) {

           
            if (mp[s[j]] > 0) {
                count--;
            }

            mp[s[j]]--;

           
            while (count == 0) {

           
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    ansi = i;
                    ansj = j;
                }

                
                mp[s[i]]++;

                if (mp[s[i]] > 0) {
                    count++;
                }

                i++;
            }

            j++;
        }

        if (ansi == -1) {
            return "";
        }

        string ans = "";

        for (int k = ansi; k <= ansj; k++) {
            ans += s[k];
        }

        return ans;
    }
};
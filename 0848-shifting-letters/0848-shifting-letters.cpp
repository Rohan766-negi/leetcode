class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
         string ans = s;
       
        int maxi = 0;

        for(int i = 0; i < shifts.size(); i++){
            maxi = (maxi + shifts[i]) % 26;
        }

        for(int i = 0; i < shifts.size(); i++){
            int x = shifts[i] % 26;

            shifts[i] = maxi;

            maxi = (maxi - x + 26) % 26;
        }

        for(int i = 0; i < s.size(); i++){
            ans[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        }

        return ans;
    }
};
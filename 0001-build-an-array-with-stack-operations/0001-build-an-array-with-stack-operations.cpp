class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int push = 0;

        for (int i = 1; i <= n; i++) {
            ans.push_back("Push");

            
            if (target[push] == i) {

                push++;

                if (push == target.size()) {
                    break;
                }

            } else {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
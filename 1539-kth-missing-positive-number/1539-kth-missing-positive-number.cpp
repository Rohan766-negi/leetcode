class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = 2;
        }
        int x = 1;
        int m = 0;
        while (x <= arr[arr.size() - 1]) {
            if (mp[x] != 2) {
                m++;
            }
            if (m == k) {
                return x;
            }
            x++;
        }

        return (arr[arr.size() - 1] + k-m);
    }
};
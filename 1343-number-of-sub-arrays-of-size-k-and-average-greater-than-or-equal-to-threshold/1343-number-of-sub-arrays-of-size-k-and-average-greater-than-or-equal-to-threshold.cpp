class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        int res = 0;
        for (int i = 0; i < k; i++) {
            ans = ans + arr[i];
        }
        if ((ans / k) >= threshold) {
            res++;
        }

        for (int i = k; i < arr.size(); i++) {
            ans = ans - arr[i - k] + arr[i];
            if ((ans / k) >= threshold) {
                res++;
            }
        }
        return res;
    }
};
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        sort(arr2.begin(), arr2.end());

        for(int i = 0; i < arr1.size(); i++) {
            int st = 0;
            int e = arr2.size()-1;
            bool found = false;

            while(st <= e) {
                int mid = st + (e-st)/2;

                if(arr2[mid] >= arr1[i]-d && arr2[mid] <= arr1[i]+d) {
                    found = true;
                    break;
                }
                else if(arr2[mid] < arr1[i]-d) {
                    st = mid+1;
                }
                else {
                    e = mid-1;
                }
            }

            if(found == false) {
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int size = nums.size();
        int i = 0;
        int j = 1;
  if(n==0){
    return true;
  }
        while (i < size) {

            if (nums[i] == 0 &&
                (i == 0 || nums[i - 1] == 0) &&
                (j == size || nums[j] == 0)) {

                nums[i] = 1;
                n--;
            }

            i++;
            j++;

            if (n <= 0)
                return true;
        }

        return false;
    }
};
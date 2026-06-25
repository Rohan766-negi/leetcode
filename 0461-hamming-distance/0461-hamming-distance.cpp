class Solution {
public:
    int hammingDistance(int x, int y) {
          int z = x ^ y;
        int m = 0;

        while (z != 0) {
            if (z % 2 == 1) {
                m++;
            }
            z = z / 2;
        }

        return m;
    }
};
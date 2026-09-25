class Solution {
public:

    long long power(long long a, long long b) {
        long long ans = 1;

        while(b > 0) {
            if(b % 2 == 1) {
                ans = (ans * a) % 1000000007;
            }

            a = (a * a) % 1000000007;
            b = b / 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
       
        if(n % 2 == 0) {

            long long x = power(5, n/2);
            long long y = power(4, n/2);

            return (x * y) % 1000000007;
        }

        else {

            long long x = power(5, (n/2)+1);
            long long y = power(4, n/2);

            return (x * y) % 1000000007;
        }
    }
};
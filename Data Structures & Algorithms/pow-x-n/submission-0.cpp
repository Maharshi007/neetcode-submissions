class Solution {
public:
    void pow(double x, long n, double& ans) {
        if (n == 0)
            return;
        if (n % 2 != 0)
            ans = ans * x;
        x *= x;
        n /= 2;
        pow(x, n, ans);
    }
    double myPow(double x, int n) {
        long exp = n;
        if (n < 0) {
            x = 1 / x;
            exp = -exp;
        }
        double ans = 1;
        pow(x, exp, ans);
        return ans;
    }
};
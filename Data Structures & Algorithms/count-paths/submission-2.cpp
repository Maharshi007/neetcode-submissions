// SPACE OPTIMIZATION
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,-1);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    dp[col] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if (row > 0) up = dp[col];
                    if (col > 0) left = dp[col - 1];
                    dp[col] = (up + left);
                }
            }
        }
        return dp[n - 1];
    }
};

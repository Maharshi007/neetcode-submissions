// TABULATION
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    dp[0][0] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if (row > 0) up = dp[row - 1][col];
                    if (col > 0) left = dp[row][col - 1];
                    dp[row][col] = (up + left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

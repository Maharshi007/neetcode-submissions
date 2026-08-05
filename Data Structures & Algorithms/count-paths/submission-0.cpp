class Solution {
    int countPaths(int row, int col, vector<vector<int>>& dp) {
        if (row < 0 || col < 0) return 0;
        if (row == 0 || col == 0) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        dp[row][col] = countPaths(row - 1, col, dp) + countPaths(row, col - 1, dp);
        return dp[row][col];
    }

   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m - 1, n - 1, dp);
    }
};

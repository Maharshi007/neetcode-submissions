class Solution {
   public:
    int f(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (row == 0 && col == 0) return grid[0][0];
        if (row < 0 || col < 0) return INT_MAX;
        if (dp[row][col] != -1) return dp[row][col];
        int up = f(row - 1, col, dp, grid);
        int left = f(row, col - 1, dp, grid);
        if (up != INT_MAX) up += grid[row][col];
        if (left != INT_MAX) left += grid[row][col];
        return dp[row][col] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, grid);
    }
};
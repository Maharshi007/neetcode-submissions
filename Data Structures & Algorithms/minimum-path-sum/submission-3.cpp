// SPACE OPTIMIZATION
class Solution {
public:
    public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dp(n,-1);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    dp[col] = grid[0][0];
                else {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if (row > 0) up = dp[col] + grid[row][col];
                    if (col > 0) left =  dp[col -1 ] + grid[row][col];
                    dp[col] = min(up, left);
                }
            }
        }
        return dp[n - 1];
    }
};
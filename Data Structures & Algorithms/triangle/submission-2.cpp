// TABULATION
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, -1);
        // Base case: last row
        for (int col = 0; col < n; col++) {
            dp[col] = triangle[n - 1][col];
        }
        // Bottom → Top
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                int up = triangle[row][col] + dp[col];
                int diagonal = triangle[row][col] + dp[col + 1];
                dp[col] = min(up, diagonal);
            }
        }
        return dp[0];
    }
};
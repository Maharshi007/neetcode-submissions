class Solution {
    int ways(int n, vector<int>& dp) {
        if (n <= 3) return dp[n] = n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = ways(n - 1, dp) + ways(n - 2, dp);
    }

   public:
    int climbStairs(int n) {
        // Memoization
        vector<int> dp(n + 1, -1);
        return ways(n, dp);
    }
};

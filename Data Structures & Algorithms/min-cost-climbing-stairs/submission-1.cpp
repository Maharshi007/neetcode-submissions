// memoization - TOP DOWN APPROACH
class Solution {
    int ways(int idx, int n, vector<int>& cost, vector<int>& dp) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        return dp[idx] = cost[idx] + min(ways(idx + 1, n, cost, dp), ways(idx + 2, n, cost, dp));
    }

   public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(ways(0, n, cost, dp), ways(1, n, cost, dp));
    }
};

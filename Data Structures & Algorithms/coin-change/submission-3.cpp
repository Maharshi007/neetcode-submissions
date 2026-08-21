class Solution {
    int helper(int idx, int amount, vector<int>& coins,vector<vector<int>>& dp) {
        if (amount == 0) return  0;
        if (idx >= coins.size() || amount < 0) return INT_MAX;
        if (dp[idx][amount] != -1) return dp[idx][amount];
        int take = helper(idx, amount - coins[idx], coins,dp);
        if (take != INT_MAX) take += 1;
        int notTake = helper(idx + 1, amount, coins,dp);
        return dp[idx][amount] = min(take, notTake);
    }

   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(0, amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};

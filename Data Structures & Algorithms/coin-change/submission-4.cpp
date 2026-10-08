class Solution {
   public:
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        for (int i = 0; i <= sum; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }
        for (int idx = 1; idx < n; idx++) {
            for (int target = 0; target <= sum; target++) {
                int notTake = prev[target];
                int take = 1e9;
                if (coins[idx] <= target) {
                    take = 1 + curr[target - coins[idx]];
                }
                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        return prev[sum] >= 1e9 ? -1 : prev[sum];
    }
};
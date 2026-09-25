class Solution {
   public:
    const int MOD = 1e9 + 7;
    int findWays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (j >= arr[i]) take = dp[i - 1][j - arr[i]];
                dp[i][j] = (take + notTake) % MOD;
            }
        }
        return dp[n - 1][k];
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int totalSum = 0;
        for (auto& it : arr) totalSum += it;
        if ((totalSum - diff < 0) || ((totalSum - diff) % 2 != 0)) return 0;
        return findWays(arr, ((totalSum - diff) / 2));
    }
    int findTargetSumWays(vector<int>& nums, int target) { return countPartitions(nums, target); }
};
// MEMOIZATION
class Solution {
   public:
    int ways(int idx, int n, vector<int>& nums, vector<int>& dp) {
        if (idx == 0) return dp[0] = nums[0];
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int pick = nums[idx] + ways(idx - 2, n, nums, dp);
        int notPick = ways(idx - 1, n, nums, dp);
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return ways(nums.size() - 1, nums.size(), nums, dp);
    }
};

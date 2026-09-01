// MEMOIZATION APPROACH
class Solution {
   public:
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (idx == 0) return nums[0] == target;
        if (dp[idx][target] != -1) return dp[idx][target];
        int notTake = f(idx - 1, target, nums,dp);
        int take = false;
        if (target >= nums[idx]) take = f(idx - 1, target - nums[idx], nums,dp);
        return dp[idx][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& it : nums) sum += it;
        if (sum % 2 != 0) return false;
        sum = sum / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        f(n - 1, sum, nums,dp);
        return dp[n-1][sum];
    }
};

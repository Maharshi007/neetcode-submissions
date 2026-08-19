// BOTTOM-UP APPROACH
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int pick;
            if(i == 1) pick = nums[i];
            else pick = nums[i] + dp[i-2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};

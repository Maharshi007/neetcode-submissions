class Solution {
   public:
    int ways(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == 0) return dp[0] = nums[0];
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int pick = nums[idx] + ways(idx - 2, nums, dp);
        int notPick = ways(idx - 1, nums, dp);
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        // Leave first house
        vector<int> temp1;
        for (int i = 1; i < n; i++) temp1.push_back(nums[i]);
        vector<int> dp1(temp1.size(), -1);
        int leavingFirstHouse = ways(temp1.size() - 1, temp1, dp1);
        // Leave last house
        vector<int> temp2;
        for (int i = 0; i < n - 1; i++) temp2.push_back(nums[i]);
        vector<int> dp2(temp2.size(), -1);
        int leavingLastHouse = ways(temp2.size() - 1, temp2, dp2);
        return max(leavingFirstHouse, leavingLastHouse);
    }
};

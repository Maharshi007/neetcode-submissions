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
        vector<int> temp1;
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);  // Leave first house
            if (i != n - 1) temp2.push_back(nums[i]); // Leave last house
        }  
        vector<int> dp(n, -1);
        int leavingFirstHouse = ways(temp1.size() - 1, temp1, dp);
        dp.clear();
        dp.resize(n,-1);
        int leavingLastHouse = ways(temp2.size() - 1, temp2, dp);
        return max(leavingFirstHouse, leavingLastHouse);
    }
};

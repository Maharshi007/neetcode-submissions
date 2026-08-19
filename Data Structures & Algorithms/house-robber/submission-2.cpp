// MORE SPACE OPTIMIZATION
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max({nums[0], nums[1]});
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < n; i++) {
            int pick;
            if (i == 1)
                pick = nums[i];
            else
                pick = nums[i] + prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

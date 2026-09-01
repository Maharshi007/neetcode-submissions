// SPACE OPTIMIZATION
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& it : nums) sum += it;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool>prev(target+1,false);
        vector<bool>curr(target+1,false);
        prev[0] = true;
        prev[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            curr[0] = true;
            for (int j = 1; j <= target; j++) {
                bool notTake = prev[j];
                bool take = false;
                if (j >= nums[i]) take = prev[j - nums[i]];
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};

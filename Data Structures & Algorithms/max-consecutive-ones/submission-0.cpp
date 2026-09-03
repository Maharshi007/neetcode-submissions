class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
                if (count > ans) ans = count;
            } else if (nums[i] == 0)
                count = 0;
        }
        return ans;
    }
};
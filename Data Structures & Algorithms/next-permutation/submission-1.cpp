class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int minIdx = -1, mini = 1e9, breakPt = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakPt = i;
                break;
            }
        }
        if (breakPt == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        minIdx = breakPt + 1;
        for (int i = breakPt + 1; i < n; i++) {
            if (nums[i] > nums[breakPt] && nums[i] < nums[minIdx]) {
                minIdx = i;
            }
        }
        swap(nums[breakPt], nums[minIdx]);
        reverse(nums.begin() + breakPt + 1, nums.end());
    }
};
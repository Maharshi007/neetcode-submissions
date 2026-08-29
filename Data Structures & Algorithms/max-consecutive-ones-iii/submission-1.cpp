class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroes = 0, longest = 0, left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeroes++;
            if (zeroes > k) {
                if (nums[left] == 0) zeroes--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
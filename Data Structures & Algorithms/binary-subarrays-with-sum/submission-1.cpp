// TC = O(N);
// SC = O(1)
class Solution {
   public:
    int helper(int n, int k, vector<int>& nums) {
        if(k < 0) return 0;
        int ans = 0, sum = 0, left = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > k) {
                sum -= nums[left];
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        int f1 = helper(n, k, nums);
        int f2 = helper(n, k - 1, nums);
        return f1 - f2;
    }
};
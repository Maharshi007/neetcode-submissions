// TC = O(N);
// SC = O(N)
class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefixSum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int rem = prefixSum - goal;;
            ans += mpp[rem];
            mpp[prefixSum]++;
        }
        return ans;
    }
};
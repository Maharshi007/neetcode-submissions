class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int s = i + 1;
            int e = n - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (s < e) {
                long sum = (long)nums[i] + nums[s] + nums[e];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    while (s < e && nums[s] == nums[s + 1]) s++;
                    while (s < e && nums[e] == nums[e - 1]) e--;
                    s++;
                    e--;

                }
                else if(sum < 0) s++;
                else e--;
            }
        }
        return ans;
    }
};

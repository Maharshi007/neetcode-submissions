class Solution {
    void helper(vector<int>& nums, int index, int n, int sum, vector<int>& temp,
                vector<vector<int>>& ans, int target) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (index == n || sum > target) {
            return;
        }
        temp.push_back(nums[index]);
        helper(nums, index, n, sum + nums[index], temp, ans, target);
        temp.pop_back();
        helper(nums, index + 1, n, sum, temp, ans, target);
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, 0, nums.size(), 0, temp, ans, target);
        return ans;
    }
};

// TC = O(N)
// SC = O(1)
// Fails at large testCases
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int countZero = 0;
        long long totalProd = 1;
        for (int x : nums) {
            if (x == 0) {
                countZero++;
            } else {
                totalProd *= x;
            }
        }
        for (int it = 0; it < n; it++) {
            if (nums[it] == 0 && countZero == 1)
                res[it] = totalProd;
            else if (nums[it] == 0 && countZero > 1)
                res[it] = 0;
            else if (nums[it] && !countZero)
                res[it] = totalProd/nums[it];
            else
                res[it] = 0;
        }
        return res;
    }
};

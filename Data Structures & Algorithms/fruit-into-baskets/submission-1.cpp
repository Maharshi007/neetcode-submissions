// TC = O(N)
// SC = O(N)
class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, longest = 0;
        unordered_map<int, int> mpp;
        for (int right = 0; right < n; right++) {
            mpp[fruits[right]]++;
            if (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
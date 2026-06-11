// BRUTE FORCE
// storing the frequency in map and sorting them
// TC : O(nlogn)
// SC : O(n)
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int& it : nums) {
            mpp[it]++;
        }
        vector<vector<int>> copyNums;
        for (auto& it : mpp) {
            int val = it.first;
            int freq = it.second;
            copyNums.push_back({val, freq});
        }
        sort(copyNums.begin(), copyNums.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
        int i=0;
        vector<int> ans;
        while(k)
        {
            ans.push_back(copyNums[i][0]);
            i++;
            k--;
        }
        return ans;
    }
};

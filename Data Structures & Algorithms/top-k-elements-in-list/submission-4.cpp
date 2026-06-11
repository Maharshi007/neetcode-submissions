// BUCKET SORT : Making the indices as frequencies.
// Elements represents having the ith frequency
// TC : O(N)
// SC : O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>
            mpp; // space : O(n) , wc: all elements are distinct
        int n = nums.size();
        for (int& it : nums) // TC : O(n)
            mpp[it]++;
        vector<vector<int>> bucket(
            n +
            1); // space : O(n+1) as atmost an element as frequency to be n+1
        for (auto& it : mpp) { // TC : O(m) , m is the #elements with frequency.
                               // In WC m=n if  all elements are distinct
            int val = it.first;
            int freq = it.second;
            bucket[freq].push_back(val);
        }
        vector<int> ans;
        for (int i = n; i >= 0; i--) { // O(n) if  all elements are distinct
            while (bucket[i].size() > 0 && k) {
                ans.push_back(bucket[i].back()); // back operation takes
                                                 // constant time in vector

                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};
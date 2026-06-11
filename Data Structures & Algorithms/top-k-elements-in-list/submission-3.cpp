// APPROACH -1 : USING MIN-HEAP
//  TC : O(nlogk) : WC : all integers in nums are different
//  sc : o(n): WC : all integers in nums are different
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; // O(m) space
        for (int& it : nums)
            mpp[it]++;                               // O(n) time
        priority_queue<P, vector<P>, greater<P>> mh; // min-heap
        for (auto& it : mpp) {                       // total : O(mlogk)
            int val = it.first;
            int freq = it.second;
            mh.push({freq, val}); // O(log K) time for min-heap push
            if (mh.size() > k)
                mh.pop(); // O(log K) time for min-heap deletion
        }
        vector<int> ans;    // O(k)
        while (!mh.empty()) // O(k)
        {
            ans.push_back(mh.top().second);
            mh.pop(); // O(log K) time for min-heap deletion
        }
        return ans;
    }
};
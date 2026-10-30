class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using p = pair<int, int>;
        unordered_map<int, int> mpp;
        for (const int& it : nums) mpp[it]++;
        priority_queue<p, vector<p>, greater<p>> minHeap;
        for (auto& it : mpp) {
            int freq = it.second;
            int val = it.first;
            minHeap.push({freq, val});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<int> ans;
        while (!minHeap.empty()) {
            auto it = minHeap.top();
            minHeap.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};

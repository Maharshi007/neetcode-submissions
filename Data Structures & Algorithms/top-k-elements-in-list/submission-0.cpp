class Solution {
   public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int& it : nums) mpp[it]++;
        priority_queue<P, vector<P>, greater<P>> mh;  // min-heap
        for (auto& it : mpp) {
            int val = it.first;
            int freq = it.second;
            mh.push({freq, val});
            if (mh.size() > k) mh.pop();
        }
        vector<int> ans;
        while(!mh.empty())
        {
            ans.push_back(mh.top().second);
            mh.pop();
        }
        return ans;
    }
};

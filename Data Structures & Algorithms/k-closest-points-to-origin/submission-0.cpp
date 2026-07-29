class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int, pair<int, int>> p;
        priority_queue<p> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            maxHeap.push({(points[i][0] * points[i][0]) + (points[i][1] * points[i][1]),
                         {points[i][0], points[i][1]}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
         vector<vector<int>> ans;
         while(!maxHeap.empty()){
            pair<int,int> pp = maxHeap.top().second;
            ans.push_back({pp.first, pp.second});
            maxHeap.pop();
         }
         return ans;
    }
};

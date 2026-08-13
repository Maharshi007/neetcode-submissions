class Solution {
    typedef pair<int, int> P;

   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>> adjList(n + 1);
        vector<int> delay(n + 1, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> minHeap; // {delay,node}
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adjList[u].push_back({v, wt}); //{adjacentNode,edgeWt}
        }
        delay[k] = 0;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            int time = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            if (time > delay[node]) continue;
            for (auto& neighbor : adjList[node]) {
                int v = neighbor.first;
                int edgeWt = neighbor.second;
                if (delay[node] != INT_MAX) {
                    int newEdgeWt = time + edgeWt;
                    if (newEdgeWt < delay[v]) {
                        delay[v] = newEdgeWt;
                        minHeap.push({delay[v], v});
                    }
                }
            }
        }
        int ans = 0;
        for (int node = 1; node < n + 1; node++) {
            if (delay[node] == INT_MAX)
                return -1;
            else
                ans = max(ans, delay[node]);
        }
        return ans;
    }
};

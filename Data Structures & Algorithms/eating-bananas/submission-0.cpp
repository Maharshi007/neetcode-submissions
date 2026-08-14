class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for (auto it : piles) {
            high = max(high, it);
        }
        int ans;
        while (low <= high) {
            int cnt = 0;
            int mid = low + (high - low) / 2;
            for (auto& it : piles) {
                if (it % mid == 0) {
                    cnt += it / mid;
                } else {
                    cnt += (it / mid) + 1;
                }
            }
            if (cnt <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

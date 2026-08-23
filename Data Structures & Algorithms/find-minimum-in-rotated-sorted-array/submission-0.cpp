class Solution {
   public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, mid, ans = INT_MAX;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[low] <= arr[mid] && arr[mid] <= arr[high]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    // index = low;
                }
                return ans;
            } else {
                if (arr[low] <= arr[mid]) {
                    if (arr[low] < ans) {
                        ans = arr[low];
                        // index = low;
                    }
                    low = mid + 1;
                } else {
                    if (arr[mid] < ans) {
                        ans = arr[mid];
                        // index = mid;
                    }
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};
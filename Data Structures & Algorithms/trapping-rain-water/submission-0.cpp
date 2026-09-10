class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int maxi = max_element(height.begin(), height.end()) - height.begin();
        int water = 0;
        for (int i = 1; i < maxi; i++) {
            lmax = max(lmax, height[i]);
            water += lmax - height[i];
        }
        int rmax = height[n - 1];
        for (int i = n - 2; i >= maxi; i--) {
            rmax = max(rmax, height[i]);
            water += rmax - height[i];
        }
        return water;
    }
};

class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n - 1;
        int area, res = -1e9;
        while (i < j) {
            area = min(heights[i], heights[j]) * (j - i);
            res = max(res, area);
            if (heights[i] <= heights[j])
                i++;
            else
                j--;
        }
        return res;
    }
};

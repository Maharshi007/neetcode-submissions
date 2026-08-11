class Solution {
   private:
    void dfs(int row, int col, int prevCellValue, vector<vector<int>>& vis, int drow[], int dcol[],
             int n, int m, vector<vector<int>>& heights) {
        if (heights[row][col] < prevCellValue) return;
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]) {
                dfs(newRow, newCol, heights[row][col], vis, drow, dcol, n, m, heights);
            }
        }
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> ans;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for (int j = 0; j < m; j++) {
            dfs(0, j, INT_MIN, pacific, drow, dcol, n, m, heights);  // 1st Row
            dfs(n - 1, j, INT_MIN, atlantic, drow, dcol, n, m,
                heights);  // Last Row
        }
        for (int i = 0; i < n; i++) {
            dfs(i, 0, INT_MIN, pacific, drow, dcol, n, m, heights);  // 1st Col
            dfs(i, m - 1, INT_MIN, atlantic, drow, dcol, n, m,
                heights);  // last Col
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
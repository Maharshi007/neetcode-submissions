class Solution {
   private:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<int>>& vis, int row,
             int col,int len, int drow[], int dcol[]) {
        if (len == word.length()) return true;
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            if (newRow >= 0 && newRow < board.size() &&
                newCol >= 0 && newCol < board[0].size() &&
                board[newRow][newCol] == word[len] &&
                !vis[newRow][newCol]) {
                if (dfs(board, word, vis, newRow, newCol, len + 1, drow, dcol)) {
                    return true;
                }
            }
        }
        // Backtrack only after trying all 4 directions
        vis[row][col] = 0;
        return false;
    }
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, vis, i, j, 1, drow, dcol)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
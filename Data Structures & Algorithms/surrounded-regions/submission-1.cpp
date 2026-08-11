class Solution {
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int drow[],
             int dcol[], vector<vector<char>>& res) {
        vis[row][col] = 1;
        res[row][col] = 'O';
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++) {
            int newr = row + drow[i];
            int newc = col + dcol[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] &&
                board[newr][newc] == 'O')
                dfs(newr, newc, vis, board, drow, dcol, res);
        }
    }

   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<char>> res(n, vector<char>(m, 'X'));
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for (int i = 0; i < m; i++) {
            // First Row
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, vis, board, drow, dcol, res);
            }
            // Last Row
            if (board[n - 1][i] == 'O' && !vis[n - 1][i])
                dfs(n - 1, i, vis, board, drow, dcol, res);
        }

        for (int i = 0; i < n; i++) {
            // 1st Column
            if (board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, vis, board, drow, dcol, res);
            // Last Column
            if (board[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(i, m - 1, vis, board, drow, dcol, res);
        }
        board = res;
    }
};
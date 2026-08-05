class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, set<pair<int, int>> st, int row, int col, int len) {
        if(len == word.length()) return true;

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[len] || st.count({row, col})) return false;
        st.insert({row, col});
        bool ans = dfs(board, word, st, row + 1, col, len+1) ||
                    dfs(board, word, st, row - 1, col, len+1) ||
                    dfs(board, word, st, row, col + 1, len+1) ||
                    dfs(board, word, st, row, col - 1, len+1);
        st.erase({row, col});
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        set<pair<int, int>> st;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dfs(board, word, st, i, j, 0)) return true;
            }
        }

        return false;
    }
};
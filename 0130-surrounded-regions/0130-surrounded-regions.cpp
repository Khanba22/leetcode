class Solution {
public:
    void helper(vector<vector<char>>& board, vector<vector<bool>>& marked,
                int n, int m, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == 'X' || marked[i][j])
            return;

        marked[i][j] = true;

        helper(board, marked, n, m, i + 1, j);
        helper(board, marked, n, m, i - 1, j);
        helper(board, marked, n, m, i, j + 1);
        helper(board, marked, n, m, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> marked(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !marked[i][0])
                helper(board, marked, n, m, i, 0);
            if (board[i][m - 1] == 'O' && !marked[i][m - 1])
                helper(board, marked, n, m, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !marked[0][i])
                helper(board, marked, n, m, 0, i);
            if (board[n - 1][i] == 'O' && !marked[n - 1][i])
                helper(board, marked, n, m, n - 1, i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!marked[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

class Solution {
public:
    int helper(vector<vector<char>>& grid, vector<vector<bool>>& marked, int m,
               int n, int i, int j) {

        if (i < 0 || j < 0 || i >= n || j >= m || marked[i][j] || grid[i][j] == '0')
            return 0;

        marked[i][j] = true;
        helper(grid, marked, m, n, i, j + 1);
        helper(grid, marked, m, n, i, j - 1);
        helper(grid, marked, m, n, i + 1, j);
        helper(grid, marked, m, n, i - 1, j);

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> marked(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !marked[i][j]) {
                    res += helper(grid, marked, m, n, i, j);
                }
            }
        }
        return res;
    }
};

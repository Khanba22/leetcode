class Solution {
public:
    int findFish(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int fish = grid[i][j];
        grid[i][j] = 0;
        fish += findFish(grid, i - 1, j, m, n);
        fish += findFish(grid, i, j + 1, m, n);
        fish += findFish(grid, i + 1, j, m, n);
        fish += findFish(grid, i, j - 1, m, n);
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxFish = max(maxFish, findFish(grid, i, j, m, n));
            }
        }
        return maxFish;
    }
};

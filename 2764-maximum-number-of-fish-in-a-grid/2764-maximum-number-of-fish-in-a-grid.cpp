class Solution {
public:
    int findFish(vector<vector<int>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int fishCount = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            if (x.first < 0 || x.first >= m || x.second < 0 || x.second >= n || grid[x.first][x.second] == 0) {
                continue;
            }
            fishCount += grid[x.first][x.second];
            grid[x.first][x.second] = 0;
            for (auto dir : dirs) {
                q.push({x.first + dir.first, x.second + dir.second});
            }
        }
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, findFish(grid, i, j, m, n));
                }
            }
        }
        return maxFish;
    }
};

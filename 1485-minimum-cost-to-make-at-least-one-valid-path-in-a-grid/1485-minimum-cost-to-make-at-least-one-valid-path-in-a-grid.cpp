class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> q;
        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        
        dp[0][0] = 0;
        q.push_front({0, 0});
        
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int x = curr.first;
                int y = curr.second;
                int x1 = x + directions[i].first;
                int y1 = y + directions[i].second;
                if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
                    int newCost = dp[x][y] + (grid[x][y] != i + 1 ? 1 : 0);
                    if (newCost < dp[x1][y1]) {
                        dp[x1][y1] = newCost;
                        if (grid[x][y] == i + 1) {
                            q.push_front({x1, y1});
                        } else {
                            q.push_back({x1, y1});
                        }
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

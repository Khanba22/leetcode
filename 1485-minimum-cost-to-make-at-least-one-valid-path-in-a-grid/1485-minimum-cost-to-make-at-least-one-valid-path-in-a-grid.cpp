#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        dp[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            auto [cost, cell] = pq.top();
            pq.pop();
            int x = cell.first;
            int y = cell.second;

            if (cost > dp[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                int x1 = x + directions[i].first;
                int y1 = y + directions[i].second;

                if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
                    int newCost = dp[x][y] + (grid[x][y] != i + 1 ? 1 : 0);
                    if (newCost < dp[x1][y1]) {
                        dp[x1][y1] = newCost;
                        pq.push({newCost, {x1, y1}});
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

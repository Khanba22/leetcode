class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> res(m, vector<int>(n, -1));
        deque<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    res[i][j] = 0;
                    q.push_back({i, j});
                }
            }
        }
        
        vector<vector<int>> directions = {
            {-1, 0},
            {0, -1}, 
            {1, 0}, 
            {0, 1}
        };
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int x = p.first + directions[i][0];
                int y = p.second + directions[i][1];
                
                if (x >= 0 && x < m && y >= 0 && y < n && res[x][y] == -1) {
                    res[x][y] = res[p.first][p.second] + 1;
                    q.push_back({x, y});
                }
            }
        }
        
        return res;
    }
};

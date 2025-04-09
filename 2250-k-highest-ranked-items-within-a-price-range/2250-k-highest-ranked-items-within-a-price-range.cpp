class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> que;
        vector<tuple<int, int, int, int>> itemInfo;
        que.emplace(start[0], start[1]);
        if (grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]) itemInfo.emplace_back(0, grid[start[0]][start[1]], start[0], start[1]);
        grid[start[0]][start[1]] = 0;
        int dist = 1;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                auto [x, y] = que.front();
                que.pop();

                for (auto& dir: dirs) {
                    int nx = x+dir.first, ny = y+dir.second;
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 0) continue;
                    if (grid[nx][ny] >= pricing[0] && grid[nx][ny] <= pricing[1]) itemInfo.emplace_back(dist, grid[nx][ny], nx, ny);
                    grid[nx][ny] = 0;
                    que.emplace(nx, ny); 
                }
            }
            dist++;
        }
        sort(itemInfo.begin(), itemInfo.end());
        vector<vector<int>> ans;
        for (int i = 0; i < min(k, (int)itemInfo.size()); i++) {
            ans.emplace_back(vector<int>{get<2>(itemInfo[i]), get<3>(itemInfo[i])});
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid,
                                            vector<int>& pricing,
                                            vector<int>& start, int k) {

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>> pq; // max-heap <distance, price, row, col>
                                        // == top_element --> lowest rank
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> qu;
        qu.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;

        int dist = 0;
        while (!qu.empty()) {

            int size = qu.size();
            for (int i = 0; i < size; i++) {

                int curr_x = qu.front().first;
                int curr_y = qu.front().second;
                qu.pop();

                if (grid[curr_x][curr_y] >= pricing[0] &&
                    grid[curr_x][curr_y] <= pricing[1]) {
                    pq.push({dist, grid[curr_x][curr_y], curr_x, curr_y});
                    if (pq.size() > k)
                        pq.pop();
                }

                for (auto dir : dirs) {

                    int new_x = curr_x + dir[0];
                    int new_y = curr_y + dir[1];

                    if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n ||
                        grid[new_x][new_y] == 0 ||
                        visited[new_x][new_y] == true)
                        continue;

                    qu.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                }
            }

            dist++;
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top()[2], pq.top()[3]});
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
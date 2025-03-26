class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                values.push_back(grid[i][j]);
            }
        }

        sort(values.begin(), values.end());
        int median = values[values.size() / 2];
        int operations = 0;

        for (int val : values) {
            if (abs(val - values[0]) % x != 0) {
                return -1;
            }
            operations += abs(val - median) / x;
        }
        return operations;
    }
};
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixTop(n, 0), prefixBottom(n, 0);
        prefixTop[0] = grid[0][0];
        prefixBottom[0] = grid[1][0];
        
        for (int i = 1; i < n; i++) {
            prefixTop[i] = prefixTop[i - 1] + grid[0][i];
            prefixBottom[i] = prefixBottom[i - 1] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long scoreTop = prefixTop[n - 1] - prefixTop[i];
            long long scoreBottom = (i > 0) ? prefixBottom[i - 1] : 0;
            long long secondPlayerMax = max(scoreTop, scoreBottom);
            result = min(result, secondPlayerMax);
        }
        
        return result;
    }
};

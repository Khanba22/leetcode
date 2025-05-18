class Solution {
public:
    int m, n;

    bool isPrime(int num) {
        if (num <= 10) return false;
        for (int i = 2; i * i <= num; ++i)
            if (num % i == 0) return false;
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        vector<pair<int, int>> directions = {
            {0, 1},  {1, 1},  {1, 0},  {1, -1},
            {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
        };

        unordered_map<int, int> freq;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto& [dx, dy] : directions) {
                    int x = i, y = j;
                    int num = 0;

                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        num = num * 10 + mat[x][y];
                        freq[num]++;
                        x += dx;
                        y += dy;
                    }
                }
            }
        }

        int maxFreq = 0, result = -1;
        for (auto& [number, count] : freq) {
            if (isPrime(number)) {
                if (count > maxFreq || (count == maxFreq && number > result)) {
                    maxFreq = count;
                    result = number;
                }
            }
        }

        return result;
    }
};

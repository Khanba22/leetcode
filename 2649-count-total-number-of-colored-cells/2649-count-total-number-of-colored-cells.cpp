class Solution {
public:
    long long coloredCells(int n) {
        long long count = 0;
        for (int i = n - 1; i >= 0; i--) {
            count += 2 * (long long)i + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            count += 2 * (long long)i + 1;
        }
        return count;
    }
};
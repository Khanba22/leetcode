class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int n = d.size();
        vector<long long> arr(n + 1, 0);
        arr[n] = lower;

        long long minVal = 0, maxVal = 0;
        long long current = 0;

        for (int i = 0; i < n; ++i) {
            current += d[i];
            minVal = min(minVal, current);
            maxVal = max(maxVal, current);
        }

        long long range = (upper - lower) - (maxVal - minVal) + 1;
        return max(0LL, range);
    }
};

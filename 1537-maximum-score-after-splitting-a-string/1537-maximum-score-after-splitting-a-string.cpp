class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zSum(n, 0);
        vector<int> oSum(n, 0);

        for (int i = 0; i < n; i++) {
            zSum[i] = (s[i] == '0' ? 1 : 0) + (i > 0 ? zSum[i - 1] : 0);
        }

        for (int i = n - 1; i >= 0; i--) {
            oSum[i] = (s[i] == '1' ? 1 : 0) + (i < n - 1 ? oSum[i + 1] : 0);
        }

        int maxSum = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            maxSum = max(maxSum, zSum[i] + oSum[i + 1]);
        }

        return maxSum;
    }
};

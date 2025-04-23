class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for (int length = 1; length <= high; ++length) {
            if (length - zero >= 0) {
                dp[length] = (dp[length] + dp[length - zero]) % MOD;
            }
            if (length - one >= 0) {
                dp[length] = (dp[length] + dp[length - one]) % MOD;
            }
        }

        int res = 0;
        for (int length = low; length <= high; ++length) {
            res = (res + dp[length]) % MOD;
        }

        return res;
    }
};

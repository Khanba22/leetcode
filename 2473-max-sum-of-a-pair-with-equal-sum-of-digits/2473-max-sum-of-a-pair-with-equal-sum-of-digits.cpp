class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int dp[82] = {0};
        int ans = -1;
        for (int x : nums) {
            int sum = 0, temp = x;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            if (dp[sum]) ans = max(ans, x + dp[sum]);
            dp[sum] = max(dp[sum], x);
        }
        return ans;
    }
};